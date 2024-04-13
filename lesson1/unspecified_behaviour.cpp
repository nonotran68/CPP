#include <iostream>
void fun(int n, int m) {}

int fun1() {
    std::cout << "fun1";
    return 1;
}
int fun2() {
    std::cout << "fun2";
    return 2;
}
int main() {
	fun(fun1(), fun2()); // which one is executed first?
	return 0;
}

