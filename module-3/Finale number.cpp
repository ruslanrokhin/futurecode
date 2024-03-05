#include <iostream>
#include <cassert>

struct Number
{
    int value_;
    Number(int tmp) : value_(tmp)
    {
    }
    int Value() const
    {
        return value_;
    }
    Number operator+(Number a) const
    {
        Number tmp(value_ + a.value_);
        return tmp;
    }
    Number &operator+=(Number a)
    {
        value_ += a.value_;
        return *this;
    }
    Number operator-(Number a) const
    {
        Number tmp(value_ - a.value_);
        return tmp;
    }
    Number &operator-=(Number a)
    {
        value_ -= a.value_;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    Number a(10);
    Number b(15);
    Number c = a + b;

    const Number d(1111);
    b = d + a;

    std::cout << c.Value(); // 25
    c += Number(100);
    std::cout << c.Value(); // 125
    static_assert(!std::is_assignable_v<decltype(d.Value()), int>);
    /*c.Value() = 0; */ // CE

    std::cout << c.Value(); // 125
    return 0;
}