
#include "shared/logger/logger.h"
#include "shared/logger/format.h"

int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    log_info << "Logger start 'Demo 07'";

    std::string s1 = ".../docker/example1.py";
    std::string s2 = ".../docker/example2.py";

//    const char* f1 = alog::__file__cache(s1.c_str());
//    const char* f2 = alog::__file__cache(s2.c_str());

//    const char* f3 = alog::__file__cache(s1.c_str());
//    const char* f4 = alog::__file__cache(s2.c_str());

    const char* file = alog::__file__cache(s1);
    alog::logger().info(file, 0, 10, "Docker") << "Message 1";

    file = alog::__file__cache(s2);
    alog::logger().info(file, 0, 20, "Docker") << "Message 2";

    file = alog::__file__cache(s1);
    alog::logger().info(file, 0, 15, "Docker") << "Message 3";

    file = alog::__file__cache(s1);
    alog::logger().info(file, 0, 17, "Docker") << "Message 4";

    file = alog::__file__cache(s2);
    alog::logger().info(file, 0, 25, "Docker") << "Message 5";

    log_info << "Logger stop";

    alog::logger().stop();
    return 0;
}
