#include <iostream>
#include <cassert>

using namespace std;

int gcd(int a, int  b) {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (a != b)
    {
        if (b < a)
        {
            b = a + b;
            a = b - a;
            b = b - a;
        }
        b = b - a;
    }
    return a;    
}

int main(int argc, char const *argv[])
{
    int a, b;
    assert(3 == gcd(8, -14));

    cin >> a >> b;

    cout << endl
         << a;
    return 0;
}