#include <iostream>

struct ReferenceHolder {
    ReferenceHolder(int& x) : x(x) {};
    ReferenceHolder(const ReferenceHolder& other) : x(other.x) { std::cout << "2"; };
    private:
    int& x;
};

int main() {
    int x = 100;
    ReferenceHolder a(x);
    ReferenceHolder b = a;
    //b.x = 200;
   // std::cout << x; // Будет 200
}