#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "log_duration.h"

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

    void InsertionSort(vector<int> &copy) const
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

    void BubbleSort(vector<int> &copy) const
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

    int Partition(vector<int> &v, int start, int end) const {
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ) const {

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

    bool Check(const vector<int> &sorted) const
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
};

void Timer(int number_of_method, const ArraySorter &arr)
{
    auto copy = arr.GetCopy();
    switch (number_of_method)
    {
    case 1:
    {
        LOG_DURATION("BubbleSort"s);
        arr.BubbleSort(copy);
    }
    break;
    case 2:
    {
        LOG_DURATION("InsertionSort"s);
        arr.InsertionSort(copy);
    }
    break;
    case 3:
    {
        LOG_DURATION("sort"s);
        sort(copy.begin(), copy.end());
    }
    break;
    case 4:
    {
        LOG_DURATION("Quicksort"s);
        arr.Quicksort(copy, 0, copy.size() - 1);
    }
    break;
    default:
        break;
    }
    cout << arr.Check(copy) << endl;
}



int main(int argc, char const *argv[])
{
    ArraySorter arr(10000000);
    Timer(3, arr);
    Timer(4, arr);
};