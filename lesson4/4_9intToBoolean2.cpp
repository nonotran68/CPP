#include <iostream>

int main()
{
   std::cout << std::boolalpha; // in bool dưới dạng true hoặc false

   bool b1 = 4 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
   std::cout << b1 << '\n';

   bool b2 = 0 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
   std::cout << b2 << '\n';
   
   return 0;
}
