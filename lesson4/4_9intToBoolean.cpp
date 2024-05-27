#include <iostream>

int main()
{
bool bFalse { 0 }; // okay: khởi tạo thành false
bool bTrue  { 1 }; // okay: khởi tạo thành true
bool bNo    { 2 }; // error: không được phép chuyển đổi thu hẹp kiểu dữ liệu

std::cout << bFalse << bTrue << bNo << '\n';

return 0;
}
