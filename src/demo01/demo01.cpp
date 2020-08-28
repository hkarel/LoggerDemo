
#include "shared/logger/logger.h"


int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    log_info << "Logger start";
    log_info << "Hello world";
    log_info << "Logger stop";

    alog::logger().stop();
    return 0;
}
