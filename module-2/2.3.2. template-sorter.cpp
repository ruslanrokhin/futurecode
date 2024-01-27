#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct MySorter
{
    template <typename T>
    bool operator()(T a, T b)
    {
        return a < b;
    }
};


template <typename T, typename Sorter>
void sortArray(std::vector<T> &seq)
{
    Sorter sorter;
    bool check = true;
    while (check)
    {
        check = false;
        for (auto i = seq.begin(), j = i + 1; j != seq.end(); i++, j++)
        {

            if (sorter(*j, *i))
            {
                check = true;
                auto tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
};

void Print(const std::vector<int> &vec)
{
    for (auto i = vec.cbegin(); i < vec.cend(); i++)
    {

        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    MySorter sorter;
    std::vector<int> vec = {4, 2, 3, 120, 10, 15, 5, 3};
    Print(vec);
    sortArray<int, MySorter>(vec);
    Print(vec);
};