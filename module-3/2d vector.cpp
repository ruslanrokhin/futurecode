#include <iostream>

template <typename T>
struct Vector {
T x = {};
T y = {};
Vector() {}
Vector(const T& x, const T& y) : x(x) , y(y)
{}
Vector& operator+=(const Vector& another)
{
    x += another.x;
    y += another.y;
    return *this;
}
Vector& operator-=(const Vector& another)
{
    x -= another.x;
    y -= another.y;
    return *this;
}
Vector& operator*=(const T& v)
{
    x *= v;
    y *= v;
    return *this;
}
Vector& operator/=(const T& v)
{
    x /= v;
    y /= v;
    return *this;
}
};
template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
    Vector<T> tmp((a.x + b.x), (a.y + b.y));
    return tmp;
}
template <typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
{
    Vector<T> tmp((a.x - b.x), (a.y - b.y));
    return tmp;
}
template <typename T>
Vector<T> operator*(const Vector<T>& a, const T& v)
{
    Vector<T> tmp((a.x * v), (a.y * v));
    return tmp;
}
template <typename T>
Vector<T> operator*(const T& v, const Vector<T>& a)
{
    return (a * v);
}
template <typename T>
Vector<T> operator/(const Vector<T>& a, const T& v)
{
    Vector<T> tmp((a.x / v), (a.y / v));
    return tmp;
}
template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& vec)
{
   T x, y;
   in >> x >> y;
   vec.x = x;
   vec.y = y;
   return in;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vec)
{
    out << vec.x << ' ' << vec.y;
    return out;
}
int main(int argc, char const *argv[])
{
    Vector<int> vec;
    std::cin >> vec;
    Vector<int> vec2(vec);

    std::cout << vec << std::endl << vec2 << std::endl;
    return 0;
}
