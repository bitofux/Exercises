/*
 * PROJECT : EXERCISES
 * FILE    : test_log4cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-17
 * BRIEF   : log4cpp日志库
 */

#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <log4cpp/Priority.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <sstream>

class LogSingleton {
public:
    static LogSingleton& getInstance(const std::string& name,
                                     log4cpp::Priority::Value value,
                                     const std::string& layout_pattern) {
        if (log_singleton_ == nullptr) {
            log_singleton_ = new LogSingleton{name};
            // 设置记录器的优先级和是否往根记录器传递日志消息
            log_singleton_->category_.setAdditivity(false);
            log_singleton_->category_.setPriority(value);

            // 创建一个格式化器
            log4cpp::PatternLayout* layout = new log4cpp::PatternLayout{};
            layout->setConversionPattern(layout_pattern);

            // 创建一个输出对象
            log4cpp::Appender* appender = new log4cpp::OstreamAppender{"console", &std::cout};

            appender->setLayout(layout);

            // 将输出对象绑定到记录器
            log_singleton_->category_.setAppender(appender);
        }
        return *log_singleton_;
    }

    void log_info(const std::string message, ...) const {
        if (category_.getPriority() > log4cpp::Priority::INFO) {
            return;
        }
        va_list args;

        va_start(args, message);

        const char* p = message.c_str();

        // 创建一个输出字符串流对象
        std::ostringstream oss;

        while (*p != '\0') {
            // 若*p != '%'，则继续下一次循环
            if (*p != '%') {
                // 写入到字符串输出流对象中
                oss << *p;
                ++p;
                continue;
            }

            // 若*p == '%'，查看下一个字符是什么
            ++p;

            switch (*p) {
                case 'd': {  // 遇到字符类型、short类型，都会提升类型到int
                    // 获取值并写入到输出字符串流对象中
                    int integer = va_arg(args, int);
                    oss << integer;
                    break;
                }
                case 'f': {  // 遇到float会提升到double
                    float fl = va_arg(args, double);
                    oss << fl;
                    break;
                }
                case 's': {
                    const char* str = va_arg(args, char*);
                    oss << str;
                    break;
                }
                case 'l': {
                    ++p;
                    switch (*p) {
                        case 'd': {
                            long int long_integer = va_arg(args, long int);
                            oss << long_integer;
                            break;
                        }
                        case 'f': {
                            double dou = va_arg(args, double);
                            oss << dou;
                            break;
                        }
                    }
                    break;
                }
                default: {
                    oss << '%' << *p;
                    break;
                }
            }
            ++p;
        }
        printf("ssss\n");
        const std::string& st = oss.str();

        category_.info(st);
        va_end(args);
    }

private:
    class deleter {
    public:
        ~deleter() {
            delete log_singleton_;
            log_singleton_ = nullptr;
        }
    };
    LogSingleton(const std::string& name)
        : category_{log4cpp::Category::getInstance(name)} {}
    ~LogSingleton() = default;

    static deleter deleter_;
    static LogSingleton* log_singleton_;
    log4cpp::Category& category_;
};
LogSingleton* LogSingleton::log_singleton_ = nullptr;
LogSingleton::deleter LogSingleton::deleter_;

int main() {
    LogSingleton& log =
        LogSingleton::getInstance("ws.log", log4cpp::Priority::INFO, "%d [%p] %m%n");

    log.log_info("server error port: %ld,%lf", 8080l,3.14);

    return 0;
}
#if 0
int main() {
    // 创建一个记录器对象
    log4cpp::Category& category{log4cpp::Category::getInstance("ws.log")};

    // 设置优先级
    category.setPriority(log4cpp::Priority::INFO);
    category.setAdditivity(false);

    // 创建一个格式化器
    log4cpp::PatternLayout* layout{new log4cpp::PatternLayout{}};
    // 自定义格式
    layout->setConversionPattern("%d [%p] %m%n");

    // 创建一个输出对象
    log4cpp::Appender* appender = new log4cpp::OstreamAppender{"console", &std::cout};
    // 绑定一个格式化器，将layout的生命周期交给appender
    appender->setLayout(layout);

    // 将这个输出对象绑定到记录器
    category.setAppender(appender);

    // 业务代码输出日志
    category.info("server port: %d", 8080);
    category.error("accept failed: %d", 24);

    log4cpp::Category::shutdown();
}
#endif
