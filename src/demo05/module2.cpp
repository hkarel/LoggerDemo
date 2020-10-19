#include "shared/logger/logger.h"
#include "shared/logger/format.h"

#include <unistd.h>

#define log_error_m   alog::logger().error   (alog_line_location, "Module2")
#define log_warn_m    alog::logger().warn    (alog_line_location, "Module2")
#define log_info_m    alog::logger().info    (alog_line_location, "Module2")
#define log_verbose_m alog::logger().verbose (alog_line_location, "Module2")
#define log_debug_m   alog::logger().debug   (alog_line_location, "Module2")
#define log_debug2_m  alog::logger().debug2  (alog_line_location, "Module2")

void moduleFunc2()
{
    for (int i = 0; i < 10; ++i)
    {
        log_debug_m << "Func2. Message " << i;
        usleep(10);
    }
}

#undef log_error_m
#undef log_warn_m
#undef log_info_m
#undef log_verbose_m
#undef log_debug_m
#undef log_debug2_m
