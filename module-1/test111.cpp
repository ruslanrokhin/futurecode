#include <iostream>
#include <cassert>




template <typename T>
T& min( T &a, T &b)
{
   return a < b ? a : b;
}
int main()
{
    int a = 3 , b = 5;
    assert(min(a, b) == 3);
}
