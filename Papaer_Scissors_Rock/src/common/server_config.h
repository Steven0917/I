#pragma once

class ServerConfig
{
public:
	static ServerConfig& Instance();

	const int GetListeningPort();
	const int GetClientBacklogSize();
	const int GetThreadPoolSize();

private:
	ServerConfig() {};
	~ServerConfig() {};
};

