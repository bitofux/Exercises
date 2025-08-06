/*定义一个Student类，继承自Person类（见题目1），并添加学号（studentID）作为私有成员变量，以及相应的构造函数、析构函数、设置和获取学号的成员函数。在main函数中创建Student对象，并测试这些成员函数。*/

#include <iostream>

class Person {
public:
    Person() { std::cout << "Person()\n"; }
    ~Person() { std::cout << "~Person(\n)"; }

public:
    void setName(const std::string name) { this->name_ = name; }
    std::string getName() const { return this->name_; }

    void setAge(const int age) { this->age_ = age; }

    int getAge() const { return this->age_; }

private:
    std::string name_;
    int age_;
};

class Student : public Person {
public:
    Student() { std::cout << "Student()\n"; }
    ~Student() { std::cout << "~Student()\n"; }

public:
    void setStudentID(const std::string studentID) { this->studentID_ = studentID; }
    std::string getStudentID() const { return this->studentID_; }

private:
    std::string studentID_;
};

int main() {
    Student s1;

    s1.setName("boy");
    s1.setAge(19);
    s1.setStudentID("1234567");

    std::cout << "name: " << s1.getName() << ", age: " << s1.getAge()
              << ", studentID: " << s1.getStudentID() << "\n";

    return 0;
}
