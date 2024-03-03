#include <iostream>
#include <vector>
#include <cassert>

#include "FlexArray.h"

using namespace std;

int main()
{

    const FlexArray<int> Const(3);
    static_assert(!std::is_assignable_v<decltype(Const.at(3)), int>);

    FlexArray<int> flex(3);
    flex.at(0) = 1;
    flex.at(1) = 2;
    flex.at(2) = 3;
    std::cout << flex.Size() << "\n"; // 3
    assert(flex.Size() == 3);

    std::cout << flex << "\n";

    auto prod = flex * 2;

    std::cout << prod << "\n";
    // Должен вывести 1 2 3 1 2 3

    FlexArray<int> last(2);
    last.at(0) = 4;
    last.at(1) = 5;
    flex += last;

    last *= 2;
    assert(last.Size() == 4);
    // Должен вывести 1 2 3 4 5

    {
        FlexArray<int> a(2);
        std::cout << a << '\n';
        a += a += a;
        std::cout << a << '\n';
    }
    {
        FlexArray<int> a(2);
        std::cout << a << '\n';
        (a *= 2) *= 2;
        std::cout << a << '\n';
    }
}