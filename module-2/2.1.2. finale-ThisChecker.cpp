#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct ThisChecker
{
    bool IsSame(const ThisChecker& tmp) const
    {
        return &tmp == this;
    }
};


int main(int argc, char const *argv[])
{
ThisChecker a;
ThisChecker b;
std::cout << a.IsSame(b) << "\n"; // false
std::cout << a.IsSame(a) << "\n"; // true
const ThisChecker& c = a;
std::cout << c.IsSame(a) << "\n"; // true
};