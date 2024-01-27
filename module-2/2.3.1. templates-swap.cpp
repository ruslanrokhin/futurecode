#include <iostream>
#include <cassert>

template <typename T> void swap(T &a, T &b)
{
    auto c = a;
    a = b;
    b = c;
}
int main(int argc, char const *argv[])
{
    double a = 5, b = 7;
    swap(a, b);
    assert(a == 7 && b == 5);
    return 0;
}
