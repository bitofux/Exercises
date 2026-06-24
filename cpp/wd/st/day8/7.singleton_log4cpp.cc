/*
 * PROJECT : DAY8
 * FILE    : 7.singleton_log4cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-24
 * BRIEF   : 单例模式封装log4cpp
 */
#include <cstdarg>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>

class MyLog {
public:
    static MyLog& GetInstance(std::string name,
                              log4cpp::Priority::Value value,
                              std::string log_file) {
        std::call_once(once_flag_, [=]() { ptr_.reset(new MyLog{name, value, log_file}); });
        return *ptr_;
    }

    // 禁止拷贝构造和赋值运算符重载函数
    MyLog(const MyLog&) = delete;
    MyLog& operator=(const MyLog&) = delete;

    // 成员函数
    void info(const char* fmt, const char* file, const char* func, int line, ...) const {
        if (category_.getPriority() > log4cpp::Priority::INFO) {
            return;
        }
        std::ostringstream oss;

        oss << "[" << file << "->" << func << ":" << line << "] ";
        va_list args;
        va_start(args, line);

        const char* str = fmt;

        while (*str != '\0') {
            if (*str != '%') {
                oss << *str;
                ++str;
                continue;
            }

            // 若等于'%'，则再将str自增1
            ++str;
            switch (*str) {
                case 'd': {
                    int integer = va_arg(args, int);
                    oss << integer;
                    break;
                }
                case 'f': {
                    double dou = va_arg(args, double);
                    oss << dou;
                    break;
                }
                case 's': {
                    const char* ch = va_arg(args, char*);
                    oss << ch;
                    break;
                }
                default: {
                    oss << *str;
                    break;
                }
            }
            ++str;
        }
        va_end(args);

        category_.info(oss.str());
    }

private:
    MyLog(std::string sub_name, log4cpp::Priority::Value value, std::string log_file)
        : category_{log4cpp::Category::getInstance(sub_name)} {
        // 设置优先级
        category_.setPriority(value);
        category_.setAdditivity(false);

        // 创建文件输出器
        log4cpp::Appender* appender1 = new log4cpp::FileAppender{"file", log_file};
        // 创建格式化器
        log4cpp::PatternLayout* layout1 = new log4cpp::PatternLayout{};
        layout1->setConversionPattern("%d %c [%p] %m%n");
        appender1->setLayout(layout1);

        // 创建控制台输出器
        log4cpp::Appender* appender2 = new log4cpp::OstreamAppender{"console", &std::cout};
        // 创建格式化器
        log4cpp::PatternLayout* layout2 = new log4cpp::PatternLayout{};
        layout2->setConversionPattern("%d %c [%p] %m%n");
        appender2->setLayout(layout2);

        category_.setAppender(appender1);
        category_.setAppender(appender2);
    }
    ~MyLog() = default;

    friend class std::default_delete<MyLog>;

    log4cpp::Category& category_;
    static std::once_flag once_flag_;
    static std::unique_ptr<MyLog> ptr_;
};
std::once_flag MyLog::once_flag_;
std::unique_ptr<MyLog> MyLog::ptr_ = nullptr;

#define LOG_INFO(obj, fmt, ...) obj.info(fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__);

int main() {
    MyLog& log = MyLog::GetInstance("network", log4cpp::Priority::INFO, "log.txt");
    // log.info("server port: %d", __FILE__, __func__, __LINE__, 8080);
    LOG_INFO(log, "server port: %f",3.14);
}
