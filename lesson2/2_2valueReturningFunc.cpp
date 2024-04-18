#include <iostream>
int returnFive() {
    //Cau lenh return chi dinh gia tri cu the ma ham se tra ve
    return 5; //Tra ve gia tri 5 cho ham goi
}
int main() {
    std::cout << returnFive() << "\n";
    std::cout << returnFive() + 2 << "\n";

    returnFive(); // Không sao: giá trị 5 được trả về, nhưng bị bỏ qua vì main() không làm gì với nó
    return 0; 
}
