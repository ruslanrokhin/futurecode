#include <iostream>

struct SampleStruct
{
    SampleStruct()
    {
        std::cout << "default\n";
    }
    SampleStruct(const SampleStruct &)
    {
        std::cout << "copy\n";
    }
};

template <typename T>
struct ArrayStruct
{
    T *ptr = 0;
    int size = 0;
    ArrayStruct(int n) : ptr(new T[n]), size(n)
    {
        std::cout << "default\n";
    }
    ArrayStruct(const ArrayStruct& another) :
                ptr(new T[another.size]),
                size(another.size) {
        std::cout << "copy\n";
        for (int i = 0; i < size; ++i) {
            ptr[i] = another.ptr[i];
        }
    }

    ~ArrayStruct()
    {
        delete[] ptr;
    }

    ArrayStruct &operator=(const ArrayStruct &another)
    {
        delete[] ptr;
        size = another.size;
        ptr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = another.ptr[i];
        }
        return *this;
    }
};

int main()
{

    {
        ArrayStruct<double> arr(10);    // default
        // const ArrayStruct<double> copy = arr; // copy
        const ArrayStruct<double> copy(arr); // copy
        arr = copy;
    }
}