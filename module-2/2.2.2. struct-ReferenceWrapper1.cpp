#include <iostream>
#include <cassert>

struct ReferenceWrapper1
{
    int &ref_;
    ReferenceWrapper1(int  &x) : ref_(x) {}
    int &Get()
    {
        return ref_;
    }
};


int main(int argc, char const *argv[])
{
    int x = 2;
    ReferenceWrapper1 ref(x);
    ref.Get() = 15;
    assert(x == 15);
    x = 100;
    assert(ref.Get() == 100);

    int &y = ref.Get();
    y = 1;
    assert(y == x && x == ref.Get() && ref.Get() == 1);
    return 0;
}
