#include <iostream>
int main() {
	
	int x; // Biến chưa được khởi tạo

	std::cout << "Nhập một số: ";
	std::cin >> x;

	if (std::cin.fail()) { // Kiểm tra đầu vào không hợp lệ
		std::cerr << "Lỗi: Đầu vào không hợp lệ. Vui lòng nhập một số.\n";
		// Xử lý lỗi (ví dụ: yêu cầu nhập lại hoặc sử dụng giá trị mặc định)
		x = 0; // Gán giá trị mặc định (tùy chọn)
	} else {
		std::cout << "Bạn đã nhập: " << x << std::endl;
	}
	return 0;
}
