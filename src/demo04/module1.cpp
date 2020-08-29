#include "shared/logger/logger.h"
#include "shared/logger/format.h"

#include <unistd.h>

#define log_error_m   alog::logger().error  (__FILE__, __func__, __LINE__, "Module1")
#define log_warn_m    alog::logger().warn   (__FILE__, __func__, __LINE__, "Module1")
#define log_info_m    alog::logger().info   (__FILE__, __func__, __LINE__, "Module1")
#define log_verbose_m alog::logger().verbose(__FILE__, __func__, __LINE__, "Module1")
#define log_debug_m   alog::logger().debug  (__FILE__, __func__, __LINE__, "Module1")
#define log_debug2_m  alog::logger().debug2 (__FILE__, __func__, __LINE__, "Module1")

void moduleFunc1()
{
    for (int i = 0; i < 10; ++i)
    {
        log_debug_m << "Func1. Message " << i;
        usleep(10);
    }
}

#undef log_error_m
#undef log_warn_m
#undef log_info_m
#undef log_verbose_m
#undef log_debug_m
#undef log_debug2_m
