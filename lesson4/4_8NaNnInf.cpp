#include <iostream>

int main()
{
    double zero {0.0};
    double posinf { 5.0 / zero }; // vô cực dương
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // vô cực âm
    std::cout << neginf << '\n';

    double naN { zero / zero }; // không phải là một số (không hợp lý về mặt toán học)
    std::cout << naN << '\n';

    return 0;
}
