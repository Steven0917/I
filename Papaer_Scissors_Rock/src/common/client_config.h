#pragma once
#include <string>

using std::string;

class ClientConfig
{
public:
	static ClientConfig& Instance();

	const string GetHostIP();
	const int GetHostPort();

private:
	ClientConfig() {};
	~ClientConfig() {};
};

