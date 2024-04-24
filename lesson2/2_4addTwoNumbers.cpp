#include <iostream>

// Hàm add() nhận hai số nguyên làm tham số và trả về kết quả của tổng của chúng
int add(int x, int y) {
    return x + y;
}

int main() {
    std::cout << add(4, 5) << '\n';
    return 0;
}
