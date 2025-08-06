/*使用Student类
要求：
编写一个main函数，在其中创建至少两个Student对象，并通过公有成员函数设置和获取它们的属性，最后通过display()函数打印出它们的信息。
验收标准：
main函数中应能正确创建Student对象，并通过公有成员函数对对象进行操作。
应能正确打印出每个Student对象的姓名、年龄和学号
 * */
#include <iostream>

class Student {
public:
    Student() = default;
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

int main() {
    Student s1,s2;
    
    //s1
    s1.setName("wangshuai");
    s1.setAge(20);
    s1.setID("1234567");
    s1.display();

    //s2
    s2.setName("bitofux");
    s2.setAge(21);
    s2.setID("7654321");
    s2.display();

    return 0;
}
