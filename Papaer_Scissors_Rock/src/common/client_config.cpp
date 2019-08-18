#include "client_config.h"

#define HOST_IP        "127.0.0.1"
#define LISTENING_PORT 28888

ClientConfig & ClientConfig::Instance()
{
	static ClientConfig _instance; // No lock. Compiler ensure thread safe.
	return _instance;
}

const string ClientConfig::GetHostIP()
{
	return HOST_IP;
}

const int ClientConfig::GetHostPort()
{
	return LISTENING_PORT;
}
