#include <iostream>

int main()
{
    unsigned short x { 65535 }; // giá trị không dấu 16-bit lớn nhất có thể
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 nằm ngoài phạm vi của chúng ta, vì vậy chúng ta có modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 nằm ngoài phạm vi của chúng ta, vì vậy chúng ta có modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    return 0;
}
