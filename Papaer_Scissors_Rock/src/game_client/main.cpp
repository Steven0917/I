#include "client.h"
#include "glog/logging.h"

using namespace std;
using namespace google;
using namespace PUMA::Kernel;

/* Start google log system */
void InitLogger()
{
    FLAGS_alsologtostderr = 1;
    InitGoogleLogging("Game.PSR_");
    SetStderrLogging(GLOG_ERROR);
    FLAGS_colorlogtostderr = true;
    FLAGS_logbufsecs = 0;
    FLAGS_max_log_size = 1024;
    FLAGS_stop_logging_if_full_disk = true;
}

void ShutdownLogger()
{
    ShutdownGoogleLogging();
}

/* Init Environment: configuration, logger, etc. */
void Init()
{
    InitLogger();
}

void Clearup()
{
    ShutdownLogger();
}

int main()
{
    try
    {
        Init();
        PUMA::Kernel::Client client;

        // start the server and check if startup succeeded
        if (client.Start())
        {
			client.Run();
        }

        LOG(INFO) << "Game Paper Scissors Rock terminated.";
        Clearup();

        return 0;
    }
    catch (exception const& ex)
    {
        LOG(ERROR) << ex.what();
        return -1;
    }
}