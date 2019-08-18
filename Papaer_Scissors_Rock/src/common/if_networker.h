#pragma once

namespace PUMA {
namespace Kernel {

enum NW_STATUS
{
	NW_OK, NW_ERROR
};

class INetworker
{
public:
	INetworker() {};
	virtual ~INetworker() {};

	virtual NW_STATUS Setup() = 0;
	virtual NW_STATUS ShutDown() = 0;

	virtual NW_STATUS Send(char* data, int dataSize) = 0;
	virtual NW_STATUS Receive(char* buffer, int bufferSize) = 0;

	virtual NW_STATUS Connect(const char* ip, unsigned short port) = 0;
	virtual NW_STATUS Bind(const char* ip, unsigned short port) = 0;
	virtual NW_STATUS StartListening(int sizeOfPendingQueue) = 0;
	virtual INetworker& Accept() = 0;

	virtual bool isValid() = 0;
	virtual NW_STATUS InitServer() = 0;
	virtual NW_STATUS InitClient() = 0;

};

}  // namespace Kernel
}  // namespace PUMA