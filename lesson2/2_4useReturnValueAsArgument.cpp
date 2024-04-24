#include <iostream>
int getValueFromUser() { // Hàm này hiện trả về một giá trị kiểu số nguyên
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;
    return input; // Trả về giá trị người dùng nhập cho hàm gọi
}
void printDoubles(int value) {
    std::cout << value << " doubled is: " << value * 2 << '\n';
}
int main() {
    printDoubles(getValueFromUser());

    return 0;
}
