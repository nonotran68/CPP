#include <iostream>

int main () {
	int x;								// định nghĩa biến x để chứa đầu vào của người dùng (và khởi tạo giá trị cho nó)
	std::cout << "Enter a number: ";	// yêu cầu người dùng nhập số
	std::cin >> x;						// lấy số từ bàn phím và lưu trữ trong biến x
	std::cout << "You entered " << x << '\n';
	return 0;
}
