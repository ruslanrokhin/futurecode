#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Print(const std::vector<int> &vec)
{
    for (auto i = vec.cbegin(); i < vec.cend(); i++)
    {

        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
bool comp(T a, T b) {
    return b < a;
}

bool comp1(int a, int b) {
    return b < a;
}

int main(int argc, char const *argv[])
{
    std::vector vec = {4, 2, 3, 120, 10};
    Print(vec);

    std::sort(vec.begin(),vec.end(), comp1);
    Print(vec);

    typename COMP = bool (*)(int a, int b);
    COMP g;

    std::cout << (*g)(4,5) << std::endl;;

    std::sort(vec.begin(),vec.end(), g);
    Print(vec);

    //auto f = &comp<int>;
    bool (*f)(int a, int b) = &comp<int>;
    std::sort(vec.begin(),vec.end(), f);
    Print(vec);

    std::sort(vec.begin(),vec.end(), comp<int>);
    Print(vec);
}
