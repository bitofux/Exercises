// 矩阵类的乘法运算符重载
// 定义一个矩阵类Matrix，包含矩阵的行数、列数和存储矩阵元素的二维数组。重载乘法操作符*，使得两个Matrix对象相乘时，能够返回一个新的Matrix对象，其元素为两个操作数矩阵对应元素乘积的和（即矩阵乘法）
#include <cassert>
#include <iostream>

class Matrix {
public:
    Matrix(const std::size_t row, const std::size_t col)
        : row_{row},
          col_{col},
          data_{new int[row_ * col_]{}} {}
    ~Matrix() {
        delete[] data_;
        data_ = nullptr;
    }
    // 禁用拷贝和赋值
    Matrix(const Matrix& other) = delete;
    Matrix& operator=(const Matrix& other) = delete;
    // 禁用移动赋值
    Matrix& operator=(Matrix&& other) = delete;
    // 移动拷贝构造函数
    Matrix(Matrix&& other) noexcept
        : row_{other.row_},
          col_{other.col_},
          data_{other.data_} {
        other.row_ = 0;
        other.col_ = 0;
        other.data_ = nullptr;
        std::cout << "Matrix(Matrix&&)\n";
    }
    std::size_t get_row() const { return row_; }
    std::size_t get_col() const { return col_; }
    // 重载[]运算符
    // idx是行数
    // 返回值是每行的首地址
    // 非const
    int* operator[](std::size_t idx) noexcept {
        assert(idx < row_);
        return data_ + (idx * col_);
    }
    // const
    const int* operator[](std::size_t idx) const noexcept {
        assert(idx < row_);
        return data_ + (idx * col_);
    }
    // 重载*运算符
    // 利用矩阵乘法得到一个新的矩阵
    // 返回一个右值
    Matrix operator*(const Matrix& other) const {
        assert(col_ == other.row_);
        Matrix tmp{row_, other.col_};
        for (std::size_t i = 0; i < tmp.row_; i++) {
            for (std::size_t j = 0; j < tmp.col_; j++) {
                int sum{0};
                for (std::size_t k = 0; k < col_; k++) {
                    sum += (*this)[i][k] * other[k][j];
                }
                tmp[i][j] = sum;
            }
        }
        return tmp;
    }

private:
    friend std::ostream& operator<<(std::ostream& os, const Matrix& other);
    std::size_t row_;  // 行数
    std::size_t col_;  // 列数
    int* data_;        // 矩阵
};

std::ostream& operator<<(std::ostream& os, const Matrix& other) {
    for (std::size_t i = 0; i < other.row_; i++) {
        os << '[';
        for (std::size_t j = 0; j < other.col_; j++) {
            if (j == other.col_ - 1) {
                os << other[i][j];
                break;
            }
            os << other[i][j] << ' ';
        }
        os << ']' << '\n';
    }
    return os;
}
void test() {
    Matrix m1{2, 3};
    for (std::size_t i = 0; i < m1.get_row(); i++) {
        for (std::size_t j = 0; j < m1.get_col(); j++) {
            m1[i][j] = (i + 1) * (j + 1);
        }
    }
    std::cout << m1;
    std::cout << "---------------------\n";
    Matrix m2{3, 4};
    for (std::size_t i = 0; i < m2.get_row(); i++) {
        for (std::size_t j = 0; j < m2.get_col(); j++) {
            m2[i][j] = (i + 2) * (j + 2);
        }
    }
    std::cout << m2;
    std::cout << "---------------------\n";

    Matrix m3{m1 * m2};
    std::cout << m3;
}

int main() { test(); }
