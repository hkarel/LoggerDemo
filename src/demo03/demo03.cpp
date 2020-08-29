
#include "shared/logger/logger.h"
#include "shared/logger/format.h"
#include "shared/thread/thread_utils.h"

#include <thread>
#include <unistd.h>

using namespace alog;

int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    const char* saverName = "default";
    const char* filePath = "/tmp/logger-demo03.log";
    Level logLevel = Level::Debug;
    bool logContinue = true;

    { //Block for SaverPtr
        SaverPtr saver {new SaverFile(saverName, filePath, logLevel, logContinue)};
        logger().addSaver(saver);
    }

    log_info << "Logger start 'Demo 03'";
    logger().flush();

    log_info << "See output in file " << filePath;
    log_info << "LWP and ThreadId is equal";

    auto threadFunc1 = []()
    {
        for (int i = 0; i < 10; ++i)
        {
            log_debug << "Func1. Message " << i
                      << ". ThreadId: " << trd::gettid();
            usleep(10);
        }
    };
    auto threadFunc2 = []()
    {
        for (int i = 0; i < 10; ++i)
        {
            log_debug << "Func2. Message " << i
                      << ". ThreadId: " << trd::gettid();
            usleep(10);
        }
    };

    std::thread t1 {threadFunc1};
    std::thread t2 {threadFunc2};

    t1.join();
    t2.join();

    log_info << "Logger stop";

    logger().flush();
    logger().waitingFlush();

    logger().stop();
    return 0;
}
