#include <iostream>
#include <fstream>

int main() {
    std::ofstream write_to_file;
    std::ifstream read_from_file;
    std::string txt_to_write{""};
    std::string txt_from_read{""};

    //以写的方式打开文件
    write_to_file.open("./test.txt",std::ios_base::out | std::ios_base::trunc);
    if (write_to_file.is_open()) {
        write_to_file << "Beginning of File\n";
        std::cout << "Enter data to write : ";
        getline(std::cin,txt_to_write);
        write_to_file << txt_to_write;
        write_to_file.close();
    }

    //以读的方式打开文件
    read_from_file.open("./test.txt",std::ios_base::in);
    if (read_from_file.is_open()) {
        while (read_from_file.good()) {
            getline(read_from_file,txt_from_read);
            std::cout << txt_from_read << std::endl;
        }
    }
    read_from_file.close();
}
