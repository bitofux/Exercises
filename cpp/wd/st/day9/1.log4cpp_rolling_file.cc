/*
 * PROJECT : EXERCISES
 * FILE    : 1.log4cpp_rolling_file.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-25
 * BRIEF   : 回卷
 */
#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

void test1() {
    // 拿到根记录器对象
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::WARN);

    // 创建一个回卷文件输出器
    log4cpp::Appender* appender = new log4cpp::RollingFileAppender{"roll", "log.txt", 50, 3};
    // 创建一个对应的格式化器
    log4cpp::PatternLayout* layout1 = new log4cpp::PatternLayout{};
    layout1->setConversionPattern("%d [%p] %m%n");

    // 输出器绑定一个格式化器
    appender->setLayout(layout1);

    root.setAppender(appender);

        root.warn("hello warn,server port: %d ip: %s", 8080, "127.0.0.1");
        root.debug("hello warn,server port: %d ip: %s", 8080, "127.0.0.1");
        root.error("hello warn,server port: %d ip: %s", 8080, "127.0.0.1");
}

int main() {
    test1();

    return 0;
}
