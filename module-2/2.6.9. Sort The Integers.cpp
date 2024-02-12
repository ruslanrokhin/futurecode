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

namespace MergeSort
{

    void merge(vector<int> &list, int start, int end, int mid)
    {
        static vector<int> mergedList(list.size());
        int i, j, k;
        i = start;
        k = start;
        j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (list[i] < list[j])
            {
                mergedList[k] = list[i];
                k++;
                i++;
            }
            else
            {
                mergedList[k] = list[j];
                k++;
                j++;
            }
        }

        while (i <= mid)
        {
            mergedList[k] = list[i];
            k++;
            i++;
        }

        while (j <= end)
        {
            mergedList[k] = list[j];
            k++;
            j++;
        }

        for (i = start; i < k; i++)
        {
            list[i] = mergedList[i];
        }
    }
    void mergeSort(vector<int> &list, int start, int end)
    {
        int mid;
        if (start < end)
        {

            mid = (start + end) / 2;
            mergeSort(list, start, mid);
            mergeSort(list, mid + 1, end);
            merge(list, start, end, mid);
        }
    }

}

void MergeSortMetod(vector<int> &copy)
{
    MergeSort::mergeSort(copy, 0, copy.size() - 1);
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
    MergeSortMetod(v);
    Print(v);
};