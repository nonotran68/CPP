#include <iostream>
void doNothing(int&) {}
int main()
{
    // Định nghĩa một biến integer có tên x
    int x; // Biến này chưa được khởi tạo vì chúng tôi chưa gán giá trị cho nó
    doNothing(x);
    // In giá trị của x lên màn hình
    std::cout << x << '\n'; // Ai biết chúng ta sẽ nhận được gì, vì x chưa được khởi tạo

    return 0;
}
