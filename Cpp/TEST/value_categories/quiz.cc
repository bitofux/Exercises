#include <cstdio>
#include <iostream>
struct Number {
    Number() = default;
    Number(const int value)
        : value_{value} {}
    int value_ = {};
};

class T {
public:
    T(const Number &n)
        : n_{n} {}

    T(const T &) { puts("Copy C'tor"); }

    Number get() { return n_; }

private:
    Number n_;
};

static T create(Number &&n) { return T{std::move(n)}; }

int main() {
    T x = T{create(Number{42})};

    std::cout << x.get().value_ << std::endl;
}
