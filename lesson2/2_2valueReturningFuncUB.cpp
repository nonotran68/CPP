#include <iostream>

int getValueFromUserUB() {
    std::cout << "Nhap mot so nguyen: ";
    int input {};
    std::cin >> input;

    //Khong co cau lenh return!
}
int main() {
    int num = getValueFromUserUB();
    std::cout << num << "nhan doi la: " << num * 2 << '\n';
    return 0;
}
