#include <iostream>

int add(int x, int y) {
    // x và y chỉ nhìn thấy/sử dụng được trong hàm này
    return x + y;
} // y và x ra khỏi phạm vi và bị hủy ở đây
int main() {
    int a {5}; // a được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
    int b {6}; // b được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
    // a và b chỉ sử dụng được trong hàm này
    std::cout << add(a, b) << '\n'; // gọi hàm add() với x=5 và y=6

    return 0;
} // b và a ra khỏi phạm vi và bị hủy ở đây
