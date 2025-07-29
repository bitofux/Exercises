//非格式化IO
#include <iostream>
#include <fstream>

int main() {
    //读取权限打开一个文件
    std::ofstream ifs_one{"./gteline.txt",std::ios_base::in};
    //检查文件流的状态
    if (!ifs_one) {
        std::cerr << "ifs_one流对象状态错误--打开文件失败" << std::endl;
    }

    //定义存储读取到的数据的缓冲区
    
}
