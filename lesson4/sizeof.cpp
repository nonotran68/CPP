#include <iomanip> // để sử dụng std::setw (hàm này thiết lập độ rộng của đầu ra tiếp theo)
#include <iostream>

int main()
{
   std::cout << std::left; // canh chỉnh đầu ra sang trái 
   std::cout << "\n-- General Data Type Size --\n";
   std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
   std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
   std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
   std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
   std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
   std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
   std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
   std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
   std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

   return 0;
}
