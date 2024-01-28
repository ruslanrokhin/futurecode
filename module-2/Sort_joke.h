#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// typedef void(*SORT_METOD)(vector<int> & copy);
// современный вариант:
using SORT_FUNCTION = void (*)(vector<int> &copy);

bool Check(const vector<int> &sorted)
{
    auto length = sorted.size();
    for (unsigned int i = 1; i < length; i++)
    {
        if (sorted[i - 1] > sorted[i])
        {
            return false;
        }
    }
    return true;
}

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

void BubbleSort(vector<int> &copy)
{
    unsigned int length = copy.size();
    while (length > 1)
    {
        int max_index = 0;
        for (unsigned int i = 1; i < length; i++)
        {
            if (copy[i - 1] > copy[i])
            {
                auto tmp = copy[i];
                copy[i] = copy[i - 1];
                copy[i - 1] = tmp;
                max_index = i;
            }
        }
        length = max_index;
    }
}

namespace Quicksort
{
    // возвращает индекс опорного элемента, и используем ее в сортировке.
    int Partition(vector<int> &v, int start, int pivot)
    {

        int j = start;
        for (int i = start; i < pivot; ++i)
        {
            if (v[i] < v[pivot])
            {
                swap(v[i], v[j]);
                ++j;
            }
        }
        swap(v[j], v[pivot]);
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
}

void QuicksortMetod(vector<int> &copy)
{
    Quicksort::Quicksort(copy, 0, copy.size() - 1);
}

void StdSort(vector<int> &copy)
{
    sort(copy.begin(), copy.end());
}

namespace Quicksort2
{
    int partition(vector<int> &list, int start, int pivot)
    {
        int i = start;
        while (i < pivot)
        {
            if (list[i] > list[pivot] && i == pivot - 1)
            {
                swap(list[i], list[pivot]);
                pivot--;
            }

            else if (list[i] > list[pivot])
            {
                swap(list[pivot - 1], list[pivot]);
                swap(list[i], list[pivot]);
                pivot--;
            }

            else
                i++;
        }
        return pivot;
    }

    void quickSort(vector<int> &list, int start, int end)
    {
        if (start < end)
        {
            int pivot = partition(list, start, end);

            quickSort(list, start, pivot - 1);
            quickSort(list, pivot + 1, end);
        }
    }
}
void QuicksortMetod2(vector<int> &copy)
{
    Quicksort2::quickSort(copy, 0, copy.size());
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

namespace HeapSort
{
    void heapify(vector<int> &list, int listLength, int root)
    {
        int largest = root;
        int l = 2 * root + 1;
        int r = 2 * root + 2;

        if (l < listLength && list[l] > list[largest])
            largest = l;

        if (r < listLength && list[r] > list[largest])
            largest = r;

        if (largest != root)
        {
            swap(list[root], list[largest]);
            heapify(list, listLength, largest);
        }
    }
}

void HeapSortMetod(vector<int> &list)
{
    using namespace HeapSort;
    int listLength = list.size();
    for (int i = listLength / 2 - 1; i >= 0; i--)
        heapify(list, listLength, i);

    for (int i = listLength - 1; i >= 0; i--)
    {
        swap(list[0], list[i]);
        heapify(list, i, 0);
    }
}
