#include <iostream>

int add(int x, int y) {
    return x + y;
}

int multiply(int z, int w) {
    return z * w;
}
int main() {
    std::cout << add(4, 5) << '\n'; // Trong hàm add() x=4, y=5, nên x+y=9
    std::cout << add(1 + 2, 3 * 4) << '\n'; // Trong hàm add() x=3, y=12, nên x+y=15
    int a = 5;
    std::cout << add(a, a) << '\n'; //Tính phép toán 5 + 5
    std::cout << add(1, multiply(2, 3)) << '\n'; //Tính phép toán 1 + 2 * 3
    std::cout << add(1, add(2, 3)) << '\n'; //Tính phép toán 1 + (2 + 3)

    return 0;
}
