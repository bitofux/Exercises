/****************************************************
 * @file    07_1_iterator_adaptor.cc
 * @brief   迭代器适配器(预定义适配器)
 *          是除基本迭代功能外还具有扩展功能的特殊迭代器
 *          主要有四类迭代器适配器
 *              1.insert iterator(插入迭代器)
 *              2.stream iterator(流迭代器)
 *              3.reverse iterator(反向迭代器)
 *              4.move iterator(移动迭代器)C++11
 *
 * @author  bitofux
 * @date    2025-08-22
 ****************************************************/
#include <iterator>
#include "03_containers.hpp"

/*
 *1.insert_iterator
 *2.back_insert_iterator
 *3.front_insert_iterator
 * */
void test_insert_iterator() {
    std::vector<int> vec1{4, 5};
    std::vector<int> vec2{12, 14, 16, 18};
    // 查找元素16
    std::vector<int>::iterator it{std::find(vec2.begin(), vec2.end(), 16)};

    // 插入迭代器指向vec2中的it位置
    std::insert_iterator<std::vector<int>> i_iter(vec2, it);

    // 将vec1中的所有元素插入到it之前的位置
    // 也就是将4,5插入到16之前
    std::copy(vec1.begin(), vec1.end(), i_iter);
    for (const auto& ref : vec2) {
        std::cout << ref << std::endl;
    }
}

/*stream iterator*/
void test_stream_iterator() {
    std::vector<std::string> vec{"a", "b", "c"};

    // std::istream_iterator<std::string>(std::cin)将遍历
    // 来自标准输入的数据,std::istream_iterator的默认构造
    // 函数表示流的结束,back_insert_iterator(vec)返回一个
    // 后插入迭代器,指向vec末尾(不是最后一个元素)
    // 所以这段代码的意思就是复制所有标准输入的数据,并
    // 通过后插入方式放入vec.
    // std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(),
    //           std::back_inserter(vec));

    // 将vec中的所有元素复制到标准输出ostream迭代器
    // 因此vec中的所有内容都被打印到标准输出并且
    // 每个元素之间用空格分隔.
    // std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

    // 将其两个进行合并
    std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(),
              std::ostream_iterator<std::string>(std::cout, " "));
}
/*反向迭代器:reverse_iterator*/
void test_reverse_iterator() {
    std::vector<int> vec {1,2,3,4,5};
    std::reverse_iterator<std::vector<int>::iterator> ritr;
    for (ritr = vec.rbegin();ritr != vec.rend();++ritr) {
        std::cout << *ritr << std::endl;
    }
}
int main() {
    // test_insert_iterator();
    // test_stream_iterator();
    test_reverse_iterator();

    return 0;
}
