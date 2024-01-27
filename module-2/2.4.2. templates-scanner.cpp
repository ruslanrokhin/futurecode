#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// using namespace std;

template <typename T, typename Iter>
std::vector<T> scanContainer(Iter first, Iter last)
{
    std::vector<T> scan;
    for (; first != last; ++first)
    {
        scan.push_back(*first);
    }
    return scan;
}

int main(int argc, char const *argv[])
{
    int count;
    std::vector<int> copy;
    
    auto ttt = scanContainer(copy.begin(), copy.end());
    
    copy = scanContainer(copy.begin(), copy.end());

    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int tmp;
        std::cin >> tmp;
        copy.push_back(tmp);
    }
    InsertionSort(copy);
    cout << copy;
};