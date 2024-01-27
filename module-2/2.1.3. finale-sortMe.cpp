#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void InsertionSort(vector<int> &copy)
{
    unsigned int length = copy.size();
    for (unsigned int i = 1; i < length; i++)
    {
        int sorted = i - 1;
        while (sorted > -1 && copy[sorted] > copy[sorted + 1])
        {
            auto tmp = copy[sorted];
            copy[sorted] = copy[sorted + 1];
            copy[sorted + 1] = tmp;
            --sorted;
        }
    }
}

ostream &operator<<(ostream &out, const vector<int> &copy)
{
    auto i = copy.begin();
    out << *i;
    i++;
    for (; i != copy.end(); i++)
    {
        out << " " << *i;
    }
    return out;
}

int main(int argc, char const *argv[])
{
    int count;
    std::vector<int> copy;
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