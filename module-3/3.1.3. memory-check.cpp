#include <iostream>
//Напишите функцию void mySort2, которая принимает указатели на две переменные типа int x и y, после чего кладёт в первую переменную минимум из значений переменных x и y, а во вторую — максимум.

void check (int *x, int *y)
{
    if (x == y)
    {
        *x = 0;
    }
    else
    {
        *y = 1;
        *x = 1;
    }
}
int main(int argc, char const *argv[])
{
int x = 5, y = 6, z = 7;
std::cout << x << " " << y << " " << z << "\n"; // 5 6 7
check(&x, &x);
std::cout << x << " " << y << " " << z << "\n"; // 0 6 7
check(&y, &z);
std::cout << x << " " << y << " " << z << "\n"; // 0 1 1
}
