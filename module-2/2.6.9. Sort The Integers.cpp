#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(vector<int> &v, int start, int end)
{

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        if (v[i] < v[pivot])
        {
            Swap(v[i], v[j]);
            ++j;
        }
    }
    Swap(v[j], v[pivot]);
    return j;
}

void Quicksort(vector<int> &v, int start, int end)
{

    if (start < end)
    {
        int p = Partition(v, start, end);
        Quicksort(v, start, p - 1);
        Quicksort(v, p + 1, end);
    }
}

void Print(const vector<int> &container_)
{
    for (auto i = container_.cbegin(); i < container_.cend(); i++)
    {

        std::cout << *i << ' ';
    }
}

int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    vector<int> v(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> v[i];
    }
    Quicksort(v, 0, count - 1);
    Print(v);
};