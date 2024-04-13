#include <ios>
#include <iostream>	//for std::cout and std::cin
#include <limits>	//for std::numeric_limits

int main() {
	std::cout << "Enter two number separated by a space: ";
    int x, y;  // Khai báo biến để lưu trữ đầu vào của người dùng
	while (!(std::cin >> x >> y)) {
		std::cerr << "Invalid input. Please enter two number seperated by a space.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua đầu vào không hợp lệ
	}
	return 0;
}
