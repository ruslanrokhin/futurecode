#pragma once

#include <iostream>
#include <cassert>
#include <memory.h>

//#define MEMCOPY

template <typename T>
inline void my_el_cpy(T *from, T *to, unsigned count)
{
#ifdef MEMCOPY
    memcpy(from, to, sizeof(T) * count);
#else
    for (unsigned i = 0; i < count; i++)
    {
        to[i] = from[i];
    }
#endif
}

template <typename T>
struct FlexArray
{

    FlexArray()
    {
    }

    FlexArray(unsigned size) : size_(size), reserve_(size), arr_ptr_(new T[size_]())
    {
    }

    FlexArray(FlexArray<T> &&other) : size_(other.size_), reserve_(other.size_), arr_ptr_(other.arr_ptr_)
    {
        other.arr_ptr_ = nullptr;
    }

    FlexArray(const FlexArray<T> &other) : size_(other.size_), reserve_(other.size_), arr_ptr_(new T[size_]())
    {
        my_el_cpy(other.arr_ptr_, arr_ptr_, size_);
    }

    ~FlexArray()
    {
        if (arr_ptr_ != 0)
        {
            delete[] arr_ptr_;
            arr_ptr_ = nullptr;
        }
    }

    unsigned Reserve() const
    {
        return reserve_;
    }

    unsigned Size() const
    {
        return size_;
    }

    T &at(unsigned i)
    {
        return *(arr_ptr_ + i);
    }

    const T &at(unsigned i) const
    {
        return *(arr_ptr_ + i);
    }

    bool resize_reserve(unsigned new_size)
    {
        size_ = new_size;
        if (reserve_ < size_)
        {
            reserve_ = size_;
            delete[] arr_ptr_;
            arr_ptr_ = new T[size_];
            return true;
        }
        return false;
    }

    bool set_reserve(unsigned reserve)
    {
        if (reserve_ < reserve)
        {
            // auto tmp_ptr = new T[reserve];
            T *tmp_ptr = (T *)malloc(sizeof(T) * reserve);
            my_el_cpy(tmp_ptr, arr_ptr_, size_);
            reserve_ = reserve;
            free(arr_ptr_);
            arr_ptr_ = tmp_ptr;
            return true;
        }
        return false;
    }

    FlexArray<T> &operator=(const FlexArray<T> &second)
    {
        resize_reserve(second.Size());
        my_el_cpy(second.arr_ptr_, arr_ptr_, second.size_);
        return *this;
    }

    FlexArray<T> &operator=(FlexArray<T> &&second)
    {
        delete[] arr_ptr_;
        arr_ptr_ = second.arr_ptr_;
        second.arr_ptr_ = nullptr;
        return *this;
    }

    FlexArray<T> &operator+=(FlexArray<T> &second)
    {
        if (second.size_ == 0)
        {
            return *this;
        }

        unsigned new_size = size_ + second.size_;

        set_reserve(new_size);

        my_el_cpy(second.arr_ptr_, arr_ptr_ + size_, second.size_);
        size_ = new_size;
        return *this;
    }

    FlexArray<T> &operator*=(unsigned n)
    {
        if (n == 1)
        {
            return *this;
        }

        unsigned new_size = size_ * n;
        set_reserve(new_size);
        for (unsigned i = size_, j = 0; i < new_size; j++, i++)
        {
            if (j == size_)
            {
                j = 0;
            }
            arr_ptr_[i] = arr_ptr_[j];
        }
        auto tmp_ptr = arr_ptr_;
        for (size_t i = 0; i < n; i++)
        {
            tmp_ptr += size_;
            my_el_cpy(arr_ptr_, tmp_ptr, size_);
        }

        size_ = new_size;
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    unsigned size_ = 0;
    unsigned reserve_ = 0;
    T *arr_ptr_ = nullptr;
};

template <typename T>
FlexArray<T> operator*(unsigned n, const FlexArray<T> &original)
{
    if (n == 1)
    {
        return original;
    }

    unsigned size = original.Size() * n;
    FlexArray<T> tmp(size);
    for (unsigned i = 0, j = 0; i < size; i++, j++)
    {
        if (j == original.Size())
        {
            j = 0;
        }
        tmp.at(i) = original.at(j);
    }
    auto tmp_ptr = tmp.arr_ptr_;
    for (size_t i = 0; i < n; i++)
    {
        my_el_cpy(original.arr_ptr_, tmp_ptr, original.size_);
        tmp_ptr += size;
    }
    return tmp;
}

template <typename T>
FlexArray<T> operator*(const FlexArray<T> &original, unsigned n)
{
    return n * original;
}

template <typename T>
const FlexArray<T> operator+(const FlexArray<T> &first, const FlexArray<T> &second)
{
    if (first.size_ == 0)
    {
        return second;
    }
    if (second.size_ == 0)
    {
        return first;
    }
    unsigned size = first.Size() + second.Size();
    FlexArray<T> tmp(size);
    unsigned i = 0;
    auto tmp_ptr = tmp.arr_ptr_;

    my_el_cpy(first.arr_ptr_, tmp_ptr, first.size_);
    tmp_ptr += first.size_;
    my_el_cpy(second.arr_ptr_, tmp_ptr, second.size_);

    return tmp;
}

///////////////////
template <typename T>
std::ostream &operator<<(std::ostream &out, const FlexArray<T> &original)
{
    for (int i = 0; i < original.Size(); ++i)
    {
        out << original.at(i) << " ";
    }
    return out;
}