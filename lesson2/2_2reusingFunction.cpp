#include <iostream>
int getValueFromUser() {
    std::cout << "Nhập một số nguyên: ";
    int input{};
    std::cin >> input;
    return input; //Tra ve gia tri nhap tu ban phim user
}
int main() {
    int x = getValueFromUser();
    int y = getValueFromUser();
    std::cout << x << " + " << y << " = " << x + y << '\n';
    return 0;
}
