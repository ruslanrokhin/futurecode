#include <iostream>

int NUM_CREATED = 0;
int NUM_DESTROYED = 0;

struct S {
    S() = delete;
    S& operator=(const S&) = delete;
    S(const S& another) : x(another.x){
        ++NUM_CREATED;
    }
    int x;
    S(int x) : x(x) {
        ++NUM_CREATED;
    };
    ~S() {
        ++NUM_DESTROYED;
    };
};

template <typename T>
struct Allocator {
    T* allocate(size_t k) {
        void* buf = ::operator new(sizeof(T) * k,
                                     std::align_val_t(alignof(T)));
        return reinterpret_cast<T*>(buf);
    }

    void construct(T* ptr, const T& value) {
        new(ptr) T(value);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }

    void deallocate(T* ptr) {
        void* buf = ptr;
        ::operator delete(buf, std::align_val_t(alignof(T)));
    }
};

int main() {

    std::cout << sizeof(S) << "\n";

    const int k = 10;
    Allocator<S> alloc;
    S* array = alloc.allocate(k);
    for (int i = 0; i < k; ++i) {
        // alloc.construct(array + i, S{i});
        alloc.construct(array + i, S(i));
    }

    for (int i = 0; i < k; ++i) {
        std::cout << array[i].x << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < k; ++i) {
        alloc.destroy(array + i);
    }
    alloc.deallocate(array);

    std::cout << NUM_CREATED - NUM_DESTROYED; // ВЫВОД 0
}