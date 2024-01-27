#include <iostream>
#include <string>

struct PublicStruct
{
    // PublicStruct() = delete;
    //  PublicStruct() = default;
    PublicStruct() : PublicStruct(43) {
        eps = .5;
        str = "22";
    }
    int x; // Доступно всем
private:
    //     int y; // Доступно только внутри PublicStruct
    std::string str; // Доступно только внутри PublicStruct
    PublicStruct(int x) : x(x) {}

public:
    int z = 12; // Опять доступно всем
    double eps;

    const std::string &GetStr() const { return str; }
    ~PublicStruct()
    {
        std::cout << "Dst" << std::endl; // OK
    }
};

class Simple {
 public:
 int q;
};

int main()
{
    Simple s{1};
    std::cout << s.q << std::endl;        // OK

    // PublicStruct ps = PublicStruct(1);
    PublicStruct ps;                // PublicStruct(1);
    std::cout << ps.x << std::endl; // OK
    // ps.y; // CE -- y - приватный
    // ps.str; // CE -- str - приватный
    std::cout << ps.z << std::endl;        // OK
    std::cout << ps.eps << std::endl;      // OK
    std::cout << ps.GetStr() << std::endl; // OK
}