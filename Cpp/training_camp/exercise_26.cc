/*设计一个Student类
要求：
类中包含私有成员变量：姓名（std::string name）、年龄（int age）、学号（std::string id）。
提供公有的成员函数：
构造函数，用于初始化学生的姓名、年龄和学号。
getName()和setName(const std::string& newName)成员函数，用于获取和设置学生的姓名。
getAge()和setAge(int newAge)成员函数，用于获取和设置学生的年龄。
getID()和setID(const std::string& newID)成员函数，用于获取和设置学生的学号。
display()成员函数，用于打印学生的姓名、年龄和学号。*/
#include <iostream>

class Student {
public:
    Student(const std::string s_name, const int s_age, const std::string s_id)
        : name{s_name},
          age{s_age},
          id{s_id} {}

public:
    // 设置学生的姓名
    void setName(const std::string& newName) { name = newName; }
    // 获取学生的姓名
    std::string getName() const { return name; }

    // 设置学生的年龄
    void setAge(int newAge) { age = newAge; }
    // 获取学生的年龄
    int getAge() const { return age; }

    // 设置学生的学号
    void setID(const std::string& newID) { id = newID; }
    // 获取学生的学号
    std::string getID() const { return id; }

    // 打印学生信息
    void display() const {
        std::cout << "name: " << name << ", age: " << age << ", id: " << id << "\n";
    }

private:
    std::string name;
    int age;
    std::string id;
};

