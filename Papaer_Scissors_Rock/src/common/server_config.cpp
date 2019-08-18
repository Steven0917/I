#include "server_config.h"

#define LISTENING_PORT      28888
#define THREAD_POOL_SIZE    100
#define CLIENT_BACKLOG_SIZE 100

ServerConfig & ServerConfig::Instance()
{
	static ServerConfig _instance; // No lock. Compiler ensure thread safe.
	return _instance;
}

const int ServerConfig::GetListeningPort()
{
	return LISTENING_PORT;
}

const int ServerConfig::GetClientBacklogSize()
{
	return CLIENT_BACKLOG_SIZE;
}

const int ServerConfig::GetThreadPoolSize()
{
	return THREAD_POOL_SIZE;
}
