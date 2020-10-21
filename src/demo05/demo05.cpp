
#include "shared/logger/logger.h"
#include "shared/logger/config.h"
#include "shared/logger/format.h"
#include "shared/config/appl_conf.h"
#include "shared/config/logger_conf.h"
#include "shared/qt/logger_operators.h"

#include <QtCore>
#include <thread>

void moduleFunc1();
void moduleFunc2();

void stopLog()
{
    alog::logger().flush();
    alog::logger().waitingFlush();
    alog::logger().stop();
}

int main(int argc, char *argv[])
{
    using namespace alog;

    QFile confFile;
    QByteArray conf;

    // Создаем демонстрационные конфиг-файлы
    confFile.setFileName("://demo05.conf");
    confFile.open(QIODevice::ReadOnly);
    conf = confFile.readAll();
    confFile.close();

    confFile.setFileName("/tmp/logger-demo05.conf");
    confFile.open(QIODevice::WriteOnly);
    confFile.write(conf);
    confFile.close();

    confFile.setFileName("://demo05.logger.conf");
    confFile.open(QIODevice::ReadOnly);
    conf = confFile.readAll();
    confFile.close();

    confFile.setFileName("/tmp/logger-demo05.logger.conf");
    confFile.open(QIODevice::WriteOnly);
    confFile.write(conf);
    confFile.close();

    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Info);

    // Путь к основному конфиг-файлу
    QString configFile = "/tmp/logger-demo05.conf";
    if (!QFile::exists(configFile))
    {
        log_error << "Config file " << configFile << " not exists";
        stopLog();
        return 1;
    }

    config::base().setReadOnly(true);
    config::base().setSaveDisabled(true);
    if (!config::base().readFile(configFile.toStdString()))
    {
        stopLog();
        return 1;
    }

    // Создаем дефолтный сэйвер для логгера
    if (!alog::configDefaultSaver())
    {
        stopLog();
        return 1;
    }

    // Создаем дополнительные сэйверы для логгера
    alog::configExtensionSavers();
    alog::printSaversInfo();

    log_info << "Logger start 'Demo 05'";
    logger().flush();

    log_info << "See config file: /tmp/logger-demo05.conf";
    log_info << "See logger-config file: /tmp/logger-demo05.logger.conf";

    SaverList savers = logger().savers(false);
    for (Saver* saver : savers)
    {
        if (SaverFile* sf = dynamic_cast<SaverFile*>(saver))
            log_info << "See output in file " << sf->filePath();
    }
    logger().flush();

    alog::logger().removeSaverStdOut();
    alog::logger().removeSaverStdErr();

    std::thread t1 {moduleFunc1};
    std::thread t2 {moduleFunc2};

    t1.join();
    t2.join();

    log_info << "Logger stop";

    stopLog();
    return 0;
}
