#include <iostream>

int main() {
    int x = 15;
    void* ptr = &x; // В ptr лежит адрес x
    std::cout << ptr << "\n"; // Можно вывести адрес
    std::cout << ptr + 1 << "\n"; // Можно и так, но компилятор будет ругаться
    // std::cout << *ptr << "\n"; // Так нельзя, void не содержит информацию о типе
    int* ptr_x = ptr; // Так тоже нельзя

    long ll[10];
    std::cout << &ll[3] - &ll[0] << std::endl;
    std::cout << (void *)&ll[3] << ' ' << (void *)&ll[0] << std::endl;
    // std::cout << (void *)(&ll[3]) - (void *)(&ll[0]) << std::endl;


}