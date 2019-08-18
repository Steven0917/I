#pragma once

#include <winsock2.h>
#include <list>
#include <string>
#include <memory>
#include "if_networker.h"
#include "message.pb.h"
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

#define BUFFER_SIZE 1024

using namespace std;

namespace PUMA {
namespace Kernel {
	
class Networker
{
public:
    Networker();
    Networker(const Networker& networker);
    virtual ~Networker();
	virtual NW_STATUS Setup();
	virtual NW_STATUS ShutDown();
	virtual NW_STATUS Send(char* data, int dataSize);
	virtual NW_STATUS Receive(char* buffer, int bufferSize);

	virtual NW_STATUS Connect(const char* ip, unsigned short port);
	virtual NW_STATUS Bind(const char* ip, unsigned short port);
	virtual NW_STATUS StartListening(int sizeOfPendingQueue);
	virtual Networker Accept();
	virtual bool isValid();
	virtual NW_STATUS InitServer();
	virtual NW_STATUS InitClient();

	NW_STATUS SetNonBlockingMode(bool isNonBlocking);
	NW_STATUS SelectRead(long milliseconds);

    SOCKET GetSocket() const;
    static list<string> getLocalIPs();
    static NW_STATUS CleanUp();

    bool GetHostNameAddr(string& name, string& addr);
    bool GetHostName(string& name);
    bool GetPeerName(string& name);
    bool Peek(char* buffer, int size);

protected:
    SOCKET socket_;
    Networker(SOCKET newSocket);
};

}  // namespace Kernel
}  // namespace PUMA

