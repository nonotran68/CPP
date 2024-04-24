#include <iostream>

int getValueFromUser()
{
   std::cout << "Nhập một số nguyên: ";
   int input{};
   std::cin >> input;

   return input; // trả về giá trị của input cho hàm gọi
}

int main()
{
   std::cout << getValueFromUser() << '\n'; // giá trị trả về được lưu trữ ở đâu?

   return 0;
}
