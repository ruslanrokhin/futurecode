#include "log_duration.h"
#include "Sort_joke.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

static std::random_device rd;
static std::mt19937 gen(rd());

// генерация случайного числа в диапазоне 1 до 3
std::uniform_int_distribution<size_t> dis(1, 10000);

struct ArraySorter
{
    vector<int> container_;
    ArraySorter(const unsigned int size)
    {
        container_.reserve(size);
        for (unsigned int i = 0; i < size; i++)
        {
            container_.push_back(dis(gen));
        }
    }

    vector<int> GetCopy() const
    {
        vector<int> copy = container_;
        return copy;
    }
};

void Timer(const vector<int> &arr, SORT_FUNCTION metod, const char * metod_name = "")
{
    vector<int> copy = arr;
    {
        LOG_DURATION(metod_name);
        metod(copy);
    }
    cout << Check(copy) << endl;
}
int main(int argc, char const *argv[])
{
    ArraySorter arr(100000000);
    Timer(arr.container_, MergeSortMetod, "MergeSort");
    Timer(arr.container_, StdSort, "StdSort");
    Timer(arr.container_, QuicksortMetod, "QuicksortMetod");
    Timer(arr.container_, HeapSortMetod, "HeapSortMetod");
    // Timer(arr.container_, QuicksortMetod2, "QuicksortMetod2");
};