#include <iostream>

int main() {
	std::cout << "Enter two numbers seperated by a space: ";
	int x, y; // Khai báo biến để lưu trữ đầu vào của người dùng
	std::cin >> x >> y; //Lấy 2 số nhập từ bàn phím của người dùng và lưu vào trong biến x và y
	
	std::cout << "You entered " << x << " and " << y << '\n';
	return 0;
}
