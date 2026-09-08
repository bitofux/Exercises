/*
 * PROJECT : EXERCISES
 * FILE    : 17.namespace.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 命名空间
 */
#include <algorithm>
#include <cstdint>

namespace avg {
float calculate(float x, float y) { return (x + y) / 2; }
}  // namespace avg

namespace basic {
float calculate(float x, float y) { return x + y; }
}  // namespace basic

namespace Sort {
void quick_sort() {}

void insertion_sort() {}

void merge_sort() {}
namespace Comparision {
void less() {}

void greater() {}
}  // namespace Comparision
}  // namespace Sort
int main() {
#if 0
    // 使用using namespace avg
    using namespace avg;
    calculate(10.2f, 20.2f);

    // 使用using avg::calculate
    using avg::calculate;
    calculate(10.2f, 20.2f);

    avg::calculate(10.2f, 20.2f);
#endif
    using namespace avg;
    using namespace basic;

    basic::calculate(10.2f, 20.2f);

    using Sort::Comparision::less;
    less();
    Sort::Comparision::greater();

    return 0;
}
