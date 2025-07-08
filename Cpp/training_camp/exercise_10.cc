//定义一个表示图书信息的struct，包括书名(char数组),作者(char数组),出版年份(int)和价格(float) 编写一个程序,允许用户输入图书信息,并使用函数输出图书信息
#include <iostream>

struct Book {
  int year;
  float price;
  char author[30];
  char book_name[50];
};

void printBook(struct Book* book) {
  std::cout << "book_name: " << book->book_name << ", author: " << book->author << ", year: " << book->year << ", price: " << book->price << "\n";
}
int main() {
  Book book;
  //提示用户输入书籍信息
  std::cout << "请您输入书籍信息(书名、作者、年份、价格): ";
  std::cin >> book.book_name >> book.author >> book.year >> book.price; 

  printBook(&book);

  return 0;
}
