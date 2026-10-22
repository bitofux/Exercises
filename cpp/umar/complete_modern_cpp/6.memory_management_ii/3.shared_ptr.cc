/*
 * PROJECT : EXERCISES
 * FILE    : 3.shared_ptr.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-20
 * BRIEF   : shared_ptr 指针
 */

#include <iostream>
#include <memory>
#include <string>

class Project {
    std::string name_;

public:
    void SetName(const std::string& name) { name_ = name; }
    void ShowProjectDetails() const { std::cout << "[Project Name]" << name_ << "\n"; }
};

class Employee {
    std::unique_ptr<Project> ptr_;

public:
    void SetProject(const std::unique_ptr<Project>& ptr) {
        ptr_ = std::move(const_cast<std::unique_ptr<Project>&>(ptr));
    }
    const std::unique_ptr<Project>& GetProject() const { return ptr_; }
};

int main() {
    // 定义一个指向Project类型的指针
    std::unique_ptr<Project> project{new Project{}};
    project->SetName("vireo");

    // 定义若干指向Employee类型的指针
    std::unique_ptr<Employee> e1{new Employee{}};
    std::unique_ptr<Employee> e2{new Employee{}};
    std::unique_ptr<Employee> e3{new Employee{}};

    // 使其都指向同一个项目
    e1->SetProject(project);
    e2->SetProject(project);
    e3->SetProject(project);

    // 此时你可通过项目和员工类都可查看项目信息
    project->ShowProjectDetails();
    e1->GetProject()->ShowProjectDetails();
    e2->GetProject()->ShowProjectDetails();
    e3->GetProject()->ShowProjectDetails();

    return 0;
}
