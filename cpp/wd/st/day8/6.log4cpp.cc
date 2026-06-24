/*
 * PROJECT : DAY8
 * FILE    : 6.log4cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-24
 * BRIEF   : log4cpp的简单使用
 */
#include <cmath>
#include <iostream>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>

// 测试root、BasicLayout、控制台
void test1() {
    // 创建控制台输出器对象
    log4cpp::Appender* appender1 = new log4cpp::OstreamAppender{"console", &std::cout};

    // 创建格式化器对象
    log4cpp::Layout* layout1 = new log4cpp::BasicLayout{};

    // 输出器对象绑定格式化器
    appender1->setLayout(layout1);

    // 创建一个root记录器
    log4cpp::Category& root = log4cpp::Category::getRoot();

    // 设置优先级
    root.setPriority(log4cpp::Priority::INFO);
    root.setAppender(appender1);

    // 输出信息
    root.info("hello info");
    root.debug("hello debug");
    root.error("hello error");
}

// 测试root、basiclayout、文件
void test2() {
    // 创建一个文件输出器对象
    log4cpp::Appender* appender1 = new log4cpp::FileAppender{"file", "log.txt"};

    // 创建一个格式化器对象
    log4cpp::Layout* layout = new log4cpp::BasicLayout{};

    // 输出器对象绑定格式化器
    appender1->setLayout(layout);

    // 创建一个根记录器
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::DEBUG);
    root.setAppender(appender1);

    root.info("heloo file");
    root.debug("hello debug");
}

// 创建单个记录器绑定多个输出器对象，自定义格式化器
void test3() {
    // 创建一个文件输出器
    log4cpp::Appender* appender1 = new log4cpp::FileAppender{"file", "log.txt"};

    // 创建文件输出器对应的格式化器
    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout{};
    layout->setConversionPattern("%d %c [%p] %m%n");

    // 文件输出器绑定格式化器
    appender1->setLayout(layout);

    // 创建一个控制台输出器
    log4cpp::Appender* appender2 = new log4cpp::OstreamAppender{"console", &std::cout};

    // 创建控制台输出器对应的格式化器
    log4cpp::PatternLayout* layout1 = new log4cpp::PatternLayout{};
    layout1->setConversionPattern("%d %c [%p] %m%n");
    appender2->setLayout(layout1);

    // 创建一个sub记录器
    log4cpp::Category& network = log4cpp::Category::getInstance("network");
    // 设置优先级
    network.setPriority(log4cpp::Priority::DEBUG);
    // 不传递给root
    network.setAdditivity(false);

    // 绑定输出器
    network.addAppender(appender1);
    network.addAppender(appender2);

    // 输出日志信息
    network.info("hello network");
    network.debug("server port: %d", 8080);
}

// 基于test3，对message进行封装，使其含有文件名、函数名、行号
void test4() {
    // 创建一个文件输出器
    log4cpp::Appender* appender1 = new log4cpp::FileAppender{"file", "log.txt"};

    // 创建文件输出器对应的格式化器
    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout{};
    layout->setConversionPattern("%d %c [%p] %m%n");

    // 文件输出器绑定格式化器
    appender1->setLayout(layout);

    // 创建一个控制台输出器
    log4cpp::Appender* appender2 = new log4cpp::OstreamAppender{"console", &std::cout};

    // 创建控制台输出器对应的格式化器
    log4cpp::PatternLayout* layout1 = new log4cpp::PatternLayout{};
    layout1->setConversionPattern("%d %c [%p] %m%n");
    appender2->setLayout(layout1);

    // 创建一个sub记录器
    log4cpp::Category& network = log4cpp::Category::getInstance("network");
    // 设置优先级
    network.setPriority(log4cpp::Priority::DEBUG);
    // 不传递给root
    network.setAdditivity(false);

    // 绑定输出器
    network.addAppender(appender1);
    network.addAppender(appender2);

    // 创建一个字符串输出流对象
    std::ostringstream oss;
    // 要输出的格式化信息
    std::string str1 = "server port: %d";
    oss << "[" << __FILE_NAME__ << " -> " <<  __FUNCTION__ << ":" << __LINE__ << "]: "<< str1;

    // 使用记录器输出信息
    network.info(oss.str().c_str(), 8080);
}

int main() {
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}
