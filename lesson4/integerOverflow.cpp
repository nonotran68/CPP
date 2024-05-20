#include <iostream>

int main()
{
   // Giả sử số nguyên chiếm 4 byte
   int x { 2'147'483'647 }; // giá trị tối đa của một số nguyên có dấu 4 byte
   std::cout << x << '\n';

   x = x + 1; // tràn số nguyên, hành vi không xác định
   std::cout << x << '\n';

   return 0;
}
