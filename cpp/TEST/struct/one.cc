#include <iostream>
#include <string>

using person = struct Persson {
    std::string name;
    int age;
    float height;
};

int main() {
    person person1;
    person1.name = "Alice";
    person1.age = 20;
    person1.height = 5.5f;

    std::cout << "Name: " << person1.name << ", Age: " << person1.age
              << ", Height: " << person1.height << "\n";

    return 0;
}
