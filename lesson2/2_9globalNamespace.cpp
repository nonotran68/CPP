#include <iostream> // nhập khai báo của std::cout vào phạm vi toàn cục

// Tất cả các câu lệnh sau đây đều là một phần của không gian tên toàn cục

void foo(); // okay: tiền khai báo hàm
int x; // biên dịch được nhưng không khuyến khích: định nghĩa biến toàn cục không phải hằng (không có giá trị khởi tạo)
int y { 5 }; // biên dịch được nhưng không khuyến khích: định nghĩa biến toàn cục không phải hằng (có giá trị khởi tạo)
x = 5; // lỗi biên dịch: các câu lệnh thực thi không được phép trong không gian tên

int main() // okay: định nghĩa hàm
{
    return 0;
}

void goo(); // okay: tiền khai báo hàm
