
#include "shared/logger/logger.h"
#include "shared/logger/format.h"
#include "shared/thread/thread_utils.h"

#include <thread>

void moduleFunc1();
void moduleFunc2();

using namespace alog;

int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    //const char* saverName = "default";
    const char* filePath  = "/tmp/logger-demo04.log";
    const char* filePath1 = "/tmp/logger-demo04.log.module1";
    const char* filePath2 = "/tmp/logger-demo04.log.module2";
    Level logLevel = Level::Debug;
    bool logContinue = true;

    { //Block for SaverPtr
        SaverPtr saver {new SaverFile("default", filePath, logLevel, logContinue)};
        logger().addSaver(saver);
    }

    { //Block for SaverPtr
        logContinue = false;
        SaverPtr saver {new SaverFile("module1", filePath1, logLevel, logContinue)};

        FilterModulePtr filter {new FilterModule};
        filter->setMode(Filter::Mode::Include);
        filter->addModule("Module1");
        saver->addFilter(filter);

        logger().addSaver(saver);
    }

    { //Block for SaverPtr
        logContinue = false;
        SaverPtr saver {new SaverFile("module2", filePath2, logLevel, logContinue)};

        FilterModulePtr filter {new FilterModule};
        filter->setMode(Filter::Mode::Include);
        filter->addModule("Module2");
        filter->setFilteringNoNameModules(true);
        saver->addFilter(filter);

        logger().addSaver(saver);
    }

    log_info << "Logger start 'Demo 04'";
    logger().flush();

    log_info << "See output in file " << filePath;
    log_info << "See output in file " << filePath1;
    log_info << "See output in file " << filePath2;

    std::thread t1 {moduleFunc1};
    std::thread t2 {moduleFunc2};

    t1.join();
    t2.join();

    log_info << "Logger stop";

    logger().flush();
    logger().waitingFlush();

    logger().stop();
    return 0;
}
