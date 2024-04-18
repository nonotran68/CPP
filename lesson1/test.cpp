#include <iostream>

int main () {
    int a, b, c;
    a = 7; b = 3; c = (a&b) + (a|b) + (a^b);
    std::cout << "c = " << c << '\n';

    return 0;
}
