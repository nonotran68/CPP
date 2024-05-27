#include <iostream>

// Trả về true nếu x và y bằng nhau, ngược lại trả về false
bool isEqual(int x, int y)
{
   return x == y; // toán tử == trả về true nếu x bằng y, ngược lại trả về false
}

int main()
{
   std::cout << "Nhập một số nguyên: ";
   int x{};
   std::cin >> x;

   std::cout << "Nhập một số nguyên khác: ";
   int y{};
   std::cin >> y;

   std::cout << std::boolalpha; // in bool dưới dạng true hoặc false

   std::cout << x << " và " << y << " có bằng nhau không? ";
   std::cout << isEqual(x, y) << '\n'; // sẽ trả về true hoặc false

   return 0;
}
