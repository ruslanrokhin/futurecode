#include <iostream>
using namespace std;

template <typename T>
struct Allocator
{
    T *allocate(size_t n)
    {
        return static_cast<T *>(malloc(n * sizeof(T)));
    }
    void construct(T *ptr, const T &value)
    {
        // *ptr = value;
        new (ptr) T(value);
    }
    void destroy(T *ptr)
    {
        ptr->~T();
    }
    void deallocate(T *ptr, size_t n)
    {
            free(ptr);
    }

    void deallocate(T *ptr)
    {
        free(ptr);
    }
};

int main()
{
    const int k = 10;
    Allocator<int> alloc;
    int *array = alloc.allocate(k);
    for (int i = 0; i < k; ++i)
    {
        alloc.construct(array + i, i);
    }
    for (int i = 0; i < k; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < k; ++i)
    {
        alloc.destroy(array + i);
    }
    alloc.deallocate(array, k);
}
