#include <iostream>

int main() { //Chương trình này có lỗi ở đâu đó
    std::cout << "Enter an integer: ";
    int num {}; //Định nghĩa biến num là một biến kiểu nguyên
    std::cin >> num; // Lấy giá trị từ bàn phím của người dùng
    
    std::cout << "Double " << num << " is: " << num * 2 << '\n';
    std::cout << "Triple "<< num << " is: " << num * 3 << '\n';
    return 0;
}
