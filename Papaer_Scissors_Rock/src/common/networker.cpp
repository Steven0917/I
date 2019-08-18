#include "Networker.h"
#include "message_handler.h"
#include "glog/logging.h"
#include <mstcpip.h> 
#include "server_config.h"
#include "client_config.h"

#pragma comment(lib, "Ws2_32.lib")

#define MSG_HDR_SIZE 4

using namespace google::protobuf;

namespace PUMA {
namespace Kernel {

// Creates the socket that calls to the Networker's functions are forwarded to.
// Returns NW_OK if the creation of the socket was successful, NW_ERROR otherwise.
NW_STATUS Networker::Setup()
{
    int nRet = 0;
    WSADATA WsaDat;

    // Initialise Windows Sockets
    if (WSAStartup(MAKEWORD(2,2), &WsaDat)!=0)
    {
        return NW_ERROR;
    }
    
    // Create the socket
    socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_ == INVALID_SOCKET)
    {
        return NW_ERROR;
    }
    
    bool bKeepAlive = true;
    if (0 != setsockopt(socket_, SOL_SOCKET, SO_KEEPALIVE, (char*)&bKeepAlive, sizeof(bKeepAlive)))
    {
        return NW_ERROR;
    }

    // socket setup successful
    return NW_OK;
}

// Creates a connection to a server with the ip address provided as the first parameter on the port specified as second parameter.
// Returns NW_OK if the connection was successfully established, NW_ERROR otherwise.
NW_STATUS Networker::Connect(const char* ip, unsigned short port)
{
    // Resolve IP address for hostname.
    struct hostent *host;

    // Setup client socket address structure.
    SOCKADDR_IN SockAddr;
    SockAddr.sin_port         = htons(port);    // Port number
    SockAddr.sin_family       = AF_INET;        // Use the Internet Protocol (IP)

    // depending on value of parameter, select localhost or an ip address
    if(strcmp(ip, "localhost") == 0)
    {
        if ((host = gethostbyname("localhost")) == NULL)  
        {
            return NW_ERROR;
        }
        SockAddr.sin_addr.s_addr = *((unsigned long*)host -> h_addr);
    }
    else
    {
        // turn IP address from string into a form that is usable by Winsock 
        SockAddr.sin_addr.s_addr = inet_addr(ip);
    }

    // Attempt to connect to server...

    if (connect(socket_, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
    {
        return NW_ERROR;
    }

    // connection successfully established
    return NW_OK;
}

// Places the underlying socket in either non-blocking (parameter evaluates to true) or blocking mode (parameter evaluates to false)
// Returns NW_OK if the socket was successfully placed in the desired mode, NW_ERROR otherwise
NW_STATUS Networker::SetNonBlockingMode(bool isNonBlocking)
{
    u_long iMode;
    if(isNonBlocking)
    {
        // place the socket in non-blocking mode
        u_long iMode = 1;
    }
    else
    {
        // place the socket in blocking mode
        u_long iMode = 0;
    }

    if(ioctlsocket(socket_, FIONBIO, &iMode) == SOCKET_ERROR)
    {
        return NW_ERROR;
    }

    // socket was successfully placed in the desired mode
    return NW_OK;
}

// Closes and shuts down the underlying socket and cleans up winsock. Afterwards no more communication through this socket possible,
// unless set up anew.
// Returns NW_OK if the socket was shut down successfully.
NW_STATUS Networker::ShutDown()
{
    // Shutdown and close the client socket.
    if(shutdown(socket_, SD_BOTH) == SOCKET_ERROR)
    {
        return NW_ERROR;
    }

    if(closesocket(socket_) == SOCKET_ERROR)
    {
        return NW_ERROR;
    }

    // socket was closed successfully
    return NW_OK;
}

// Terminates use of the winsock library for all threads and should therefore only be called by the last thread using winsock.
NW_STATUS Networker::CleanUp()
{
    // Cleanup Winsock
    if(WSACleanup() == SOCKET_ERROR)
    {
        return NW_ERROR;
    }
    else
    {
        return NW_OK;
    }
}

// Binds the underlying socket to the ip address and port specified as parameters.
// Providing "any" as value for the ip address, will bind the socket to any ip address on the specified port.
// Returns NW_OK if the socket was successfully bound to the specified ip and port, NW_ERROR otherwise.
NW_STATUS Networker::Bind(const char* ip, unsigned short port)
{
    SOCKADDR_IN SockAddr;

    SockAddr.sin_family        = AF_INET;
    if(strcmp(ip, "any") == 0)
    {
        // bind the socket to any incoming IP address
        SockAddr.sin_addr.s_addr    = INADDR_ANY;
    }
    else
    {
        SockAddr.sin_addr.s_addr = inet_addr(ip);
    }
    SockAddr.sin_port            = htons(port);

    // global scope for bind to avoid ambiguity with bind in Networker
    if (::bind(socket_, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) == SOCKET_ERROR)
    {
        return NW_ERROR;
    }

    // the socket was successfully bound
    return NW_OK;
}

// Places the underlying socket in listening state.
// The parameter specifies how many connections can be added to the queue of pending connections.
// Returns NW_OK if the socket was successfully placed in listening state, NW_ERROR otherwise.
NW_STATUS Networker::StartListening(int sizeOfPendingQueue)
{
    // start listening for connections
    if(listen(socket_, sizeOfPendingQueue) == SOCKET_ERROR)
    {
        return NW_ERROR;
    }

    // socket successully placed in listening state
    return NW_OK;
}

// Accepts a connection with an entity trying to connect to this networker. The Networker has to be in listening state to be able
// to accept connections.
// The function returns an instance of the Networker class, that can be used to communicate with the just connected client.
// Given a Networker in non-blocking mode, the function will return an invalid Networker if there are no clients trying to connect.
// The validity of the returned Networker has to be checked by the user by calling isValid() on the returned object.
Networker Networker::Accept()
{
    SOCKET tempSock = INVALID_SOCKET;
    tempSock = accept(socket_, NULL, NULL);

    if(tempSock == INVALID_SOCKET)
    {
        return Networker(INVALID_SOCKET);
    }
    else
    {
        return Networker(tempSock);
    }
}

// Can be used to determine the status of the socket in terms of reading data from it. The function will wait for a specified
// amount of time or until there is some data readable from the socket.
// Returns NW_OK if there is something to be received on the socket.
// Returns NW_TIMEOUT if the time specified in the parameter passed without data becoming available for reading from the socket
// Returns NW_ERROR if an error occurs.
NW_STATUS Networker::SelectRead(long milliseconds)
{
    // setup the structure holding the timeout interval
    timeval tVal;
    tVal.tv_sec = milliseconds / 1000;
    tVal.tv_usec = (milliseconds % 1000) * 1000;

    // setup fd set with the socket of this Networker
    fd_set fdRead;
    FD_ZERO(&fdRead);
    FD_SET(socket_, &fdRead);

    int result = SOCKET_ERROR;

    // returns as soon as there is something to read or the time specified in tVal
    result = select(0, &fdRead, 0, 0, &tVal);

    if (result == SOCKET_ERROR)
    {
        // an error occurred
        return NW_ERROR;
    }
    else if (result == 0)
    {
        // a timeout occurred as there was nothing to receive within the specified time interval
        return NW_ERROR;
    }
    else
    {
        // there is something to be received on the socket
        return NW_OK;
    }
}

// Returns true if the Networker object is valid and be used to communicate with a client, false otherwise
bool Networker::isValid()
{
    return socket_ != INVALID_SOCKET;
}

Networker::Networker() : socket_(INVALID_SOCKET)
{
}

Networker::Networker(const Networker& networker) : socket_(networker.GetSocket())
{
}

Networker::~Networker()
{
}

Networker::Networker(SOCKET newSocket) : socket_(newSocket)
{
}

SOCKET Networker::GetSocket() const
{
    return socket_;
}

// Returns the IP addresses of the local machine as a list of strings
// If the returned list is empty, the function was not able to obtain the local IP addresses
list<string> Networker::getLocalIPs()
{
    list<string> ipAddresses;

    char ac[80];
    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) 
    {
        return ipAddresses;
    }

    struct hostent *phe = gethostbyname(ac);
    if (phe == 0) 
    {
        return ipAddresses;
    }

    for (int i = 0; phe->h_addr_list[i] != 0; ++i) 
    {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        ipAddresses.push_back(inet_ntoa(addr));
    }

    return ipAddresses;
}

NW_STATUS Networker::Send(char* buffer, int bufferSize)
{
    int totalBytesSent = 0;
    int bytesSent = 0;

    // make sure everything is sent
    while (totalBytesSent < bufferSize)
    {
        // returns 0 if connection closed, SOCKET_ERROR when error (specific error code can be retrieved by calling WSAGetLastError)
        bytesSent = ::send(socket_, reinterpret_cast<const char*>(buffer) + totalBytesSent, bufferSize - totalBytesSent, 0);
        if (bytesSent == SOCKET_ERROR)
        {
			LOG(WARNING) << "Networker Send Error: " << WSAGetLastError();
			return NW_ERROR;
        }
        totalBytesSent += bytesSent;
    }
    // everything went fine, complete data sent
    return NW_OK;
}

NW_STATUS Networker::Receive(char* buffer, int bufferSize)
{
    int totalBytesReceived = 0;
    int bytesReceived = 0;

    //LOG(INFO) << "Networker::receive: " << bufferSize;

    // make sure everything is received
    while (totalBytesReceived < bufferSize)
    {
        // returns 0 if connection closed, SOCKET_ERROR when error (specific error code can be retrieved by calling WSAGetLastError)
        bytesReceived = ::recv(socket_, reinterpret_cast<char*>(buffer) + totalBytesReceived, bufferSize - totalBytesReceived, 0);

        if (bytesReceived == SOCKET_ERROR)
        {
            if (WSAGetLastError() == WSAEWOULDBLOCK)
            {
                continue;
            }
            else
            {
                LOG(ERROR) << "NW_ERROR " << totalBytesReceived << ": " << bufferSize;
                return NW_ERROR;
            }
        }
        else if (bytesReceived == 0)
        {
            LOG(ERROR) << "NW_CONNECTION_CLOSED " << totalBytesReceived << ": " << bufferSize;
            return NW_ERROR;
        }
        totalBytesReceived += bytesReceived;
    }

    if (totalBytesReceived < bufferSize)
    {
        LOG(ERROR) << "Networker fails to receive full package " << totalBytesReceived << ": " << bufferSize;
        return NW_ERROR;
    }

    // everything went fine, complete data received
    //LOG(INFO) << "Networker received " << totalBytesReceived << " of " << bufferSize;
    return NW_OK;
}

bool Networker::GetHostNameAddr(string& name, string& addr)
{
    struct hostent *hptr;
    struct in_addr **pptr;
    char hostname[32];

    if (SOCKET_ERROR == ::gethostname(hostname, sizeof(hostname)))
    {
        LOG(ERROR) << "gethostname failed.";
        return false;
    }

    hptr = gethostbyname(hostname);
    if (!hptr)
    {
        LOG(ERROR) << "gethostbyname failed.";
        return false;
    }

    pptr = (struct in_addr **) hptr->h_addr_list;
    if (pptr && pptr[0])
    {
        addr = inet_ntoa(*pptr[0]);
    }

    name = hostname;
    return true;
}

bool Networker::GetHostName(string& name)
{

    char hostname[32];

    if (SOCKET_ERROR == ::gethostname(hostname, sizeof(hostname)))
    {
        LOG(ERROR) << "gethostname failed.";
        return false;
    }

    name = hostname;
    return true;
}

bool Networker::GetPeerName(string& name)
{
    struct sockaddr_in  sa;
    int                 len = sizeof(sa);
    if (::getpeername(socket_, (struct sockaddr *)&sa, &len))
    {
        LOG(INFO) << "Peer Name " << inet_ntoa(sa.sin_addr) << ": " << ntohs(sa.sin_port);
        stringstream ss;
        ss << inet_ntoa(sa.sin_addr) << ": " << ntohs(sa.sin_port);
        name = ss.str();
        return true;
    }
    return false;
}

bool Networker::Peek(char* buffer, int size)
{
    int totalBytesReceived = 0;
    int bytesReceived = 0;

    //LOG(INFO) << "Peek with socket " << socket_;
    bytesReceived = ::recv(socket_, buffer, size, MSG_PEEK);
    if (bytesReceived == SOCKET_ERROR)
    {
        if (WSAGetLastError() == WSAEWOULDBLOCK)
        {
            return false;
        }
        else
		{
            return false;
        }
    }
    else if (bytesReceived == 0)
    {
        return false;
    }

    return true;
}

NW_STATUS Networker::InitServer()
{
	ServerConfig& config = ServerConfig::Instance();
	if (Setup() != NW_OK)
	{
		LOG(ERROR) << "Setting up the networker failed.";
		return NW_ERROR;
	}

	if (Bind("any", config.GetListeningPort()) != NW_OK)
	{
		LOG(ERROR) << "Binding the networker failed." << endl;
		return NW_ERROR;
	}

	if (SetNonBlockingMode(true) != NW_OK)
	{
		LOG(ERROR) << "Setting the networker to non-blocking mode failed." << endl;
		return NW_ERROR;
	}

	if (StartListening(config.GetClientBacklogSize()) != NW_OK)
	{
		LOG(ERROR) << "Placing the networker in listening mode failed." << endl;
		return NW_ERROR;
	}
	else
	{
		list<string> ipAddresses = Networker::getLocalIPs();
		if (!ipAddresses.empty())
		{
			for (list<string>::iterator it = ipAddresses.begin(); it != ipAddresses.end(); ++it)
			{
				LOG(INFO) << " - " << (*it);
			}
			LOG(INFO) << " - Listening at : " << config.GetListeningPort();
		}
	}
	
	return NW_OK;
}

NW_STATUS Networker::InitClient()
{
	ClientConfig& cfg = ClientConfig::Instance();
	if (NW_OK == Setup() && NW_OK == Connect(cfg.GetHostIP().c_str(), cfg.GetHostPort())
		&& NW_OK == SetNonBlockingMode(true))
	{
		return NW_OK;
	}
	else
	{
		LOG(ERROR) << "Failed to connect to server.";
		return NW_ERROR;
	}
}

}  // namespace Kernel
}  // namespace PUMA