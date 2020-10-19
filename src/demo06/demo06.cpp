
#include "shared/logger/logger.h"
#include "shared/logger/format.h"

int main(int argc, char *argv[])
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info, true);

    log_info << "Logger start 'Demo 06'";

    //--- Тест log_format ---
    log_info << "---";
    log_info << log_format(u8"Тестовый вывод: %?, текст: %?. Вопрос?", 1, u8"значение", 2);
    log_info << log_format(u8"Тестовый вывод: %?, текст: %?. Вопрос?", 1, u8"значение", 2, 3);
    log_info << log_format(u8"Тестовый вывод: %?, текст: %?. Вопрос?", 1, u8"значение", 2, 3, 4);
    log_info << "---";
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?");
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?", 1);
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?", 1, 2);
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?", 1, 2, 3);
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?", 1, 2, 3, 4);
    log_info << log_format("Param1: %?. Param2 [%?]. Param3 %?", 1, 2, 3, 4, 5);
    log_info << "---";
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?");
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?", 1);
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?", 1, 2);
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?", 1, 2, 3);
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?", 1, 2, 3, 4);
    log_info << log_format("Param1: %?%?. Param2 [%?]. Param3 %?", 1, 2, 3, 4, 5);
    log_info << "---";
    log_info << log_format("%?");
    log_info << log_format("%?", 1);
    log_info << log_format("%?", 1, 2);
    log_info << log_format("%?", 1, 2, 3);
    log_info << log_format("%?", 1, 2, 3, 4);
    log_info << "---";
    log_info << log_format("%?%");
    log_info << log_format("%?%", 1);
    log_info << log_format("%?%", 1, 2);
    log_info << log_format("%?%", 1, 2, 3);
    log_info << log_format("%?%", 1, 2, 3, 4);
    log_info << "---";
    log_info << log_format("%?%?");
    log_info << log_format("%?%?", 1);
    log_info << log_format("%?%?", 1, 2);
    log_info << log_format("%?%?", 1, 2, 3);
    log_info << log_format("%?%?", 1, 2, 3, 4);
    log_info << "---";
    log_info << log_format("%?")             << "next string";
    log_info << log_format("%?", 1)          << "next string";
    log_info << log_format("%?", 1, 2)       << "next string";
    log_info << log_format("%?", 1, 2, 3)    << "next string";
    log_info << log_format("%?", 1, 2, 3, 4) << "next string";
    log_info << "---";
    log_info << log_format("%?%?")             << "next string";
    log_info << log_format("%?%?", 1)          << "next string";
    log_info << log_format("%?%?", 1, 2)       << "next string";
    log_info << log_format("%?%?", 1, 2, 3, 4) << "next string";
    log_info << "---";
    log_info << log_format("%? value");
    log_info << log_format("%? value", 1);
    log_info << log_format("%? value", 1, 2);
    log_info << log_format("%? value", 1, 2, 3);
    log_info << log_format("%? value", 1, 2, 3, 4);
    log_info << "---";
    log_info << log_format("%?%? value");
    log_info << log_format("%?%? value", 1);
    log_info << log_format("%?%? value", 1, 2);
    log_info << log_format("%?%? value", 1, 2, 3);
    log_info << log_format("%?%? value", 1, 2, 3, 4);

    const char* char_text = "char text0";
    log_info << log_format("%? value", char_text);
    log_info << log_format("%? value", "char text1");

    log_info << "Logger stop";

    alog::logger().stop();
    return 0;
}
