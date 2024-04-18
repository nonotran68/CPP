#include <iostream>

void doPrint() {
    std::cout << "in doPrint()\n";
}
int main() {
    std::cout << "Starting main()\n";
    doPrint();
    std::cout << "Ending main()\n";

    return 0;
}
