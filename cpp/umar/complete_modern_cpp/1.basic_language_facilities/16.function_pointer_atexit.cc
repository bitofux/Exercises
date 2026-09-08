/*
 * PROJECT : EXERCISES
 * FILE    : 16.function_pointer_atexit.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : atexit函数
 */
#include <cstdlib>
#include <iostream>

void end_message() {
    using namespace std;
    cout << "end of program" << endl;
}

void print(int count, char ch) {
    using namespace std;
    for (int i = 0; i < count; ++i) {
        cout << ch;
    }
}

int main() {
    using fun_ptr = void (*)(int, char);

    fun_ptr print_ptr = print;

    print_ptr(5, '@');
    std::cout << "\n";

    std::cout << "atexit start" << "\n";
    atexit(end_message);
    std::cout << "atexit end" << "\n";

    return 0;
}
