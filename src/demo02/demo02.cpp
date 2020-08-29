
#include "shared/logger/logger.h"
#include "shared/logger/format.h"

using namespace alog;

int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    const char* saverName = "default";
    const char* filePath = "/tmp/logger-demo02.log";
    Level logLevel = Level::Debug;
    bool logContinue = true;

    { //Block for SaverPtr
        SaverPtr saver {new SaverFile(saverName, filePath, logLevel, logContinue)};
        logger().addSaver(saver);
    }

    log_info << "Logger start 'Demo 02'";
    logger().flush();

    log_info << "See output in file " << filePath;

    for (int i = 0; i < 10; ++i)
    {
        log_debug << "Test message: " << i;
    }
    for (int i = 0; i < 10; ++i)
    {
        log_debug << log_format("Test format message: %?", i);
    }
    log_info << "Logger stop";

    logger().flush();
    logger().waitingFlush();

    logger().stop();
    return 0;
}
