#include <iostream>
int getValueFromUser() { // Hàm này hiện trả về một giá trị kiểu số nguyên
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;
    return input; // Trả về giá trị người dùng nhập cho hàm gọi
}
int main() {
    int num { getValueFromUser() }; // Khởi tạo num bằng giá trị trả về của getValueFromUser()
    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}
