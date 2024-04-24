#include <iostream>

// Hàm này có hai tham số nguyên, một tên là x và một tên là y
// Giá trị của x và y được truyền vào bởi hàm gọi
void printValues(int x, int y) {
    std::cout << x << '\n';
    std::cout << y << '\n';
}
int main() {
    printValues(6, 7);
    return 0;
}
