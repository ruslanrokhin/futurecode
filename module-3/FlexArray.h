#pragma once

#include <iostream>
#include <cassert>

template <typename T>
struct FlexArray
{

    FlexArray()
    {
    }

    FlexArray(unsigned size) : size_(size), arr_ptr_(new T[size_]())
    {
    }

    FlexArray(FlexArray<T> &&other) : size_(other.size_), arr_ptr_(other.arr_ptr_)
    {
        other.arr_ptr_ = nullptr;
    }

    FlexArray(const FlexArray<T> &other) : size_(other.size_), arr_ptr_(new T[size_]())
    {
        for (unsigned i = 0; i < size_; i++)
        {
            at(i) = other.at(i);
        }
    }

    ~FlexArray()
    {
        if (arr_ptr_ != 0)
        {
            delete[] arr_ptr_;
        }
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

    FlexArray<T> &operator=(const FlexArray<T> &second)
    {
        delete [] arr_ptr_;
        size_ = second.Size();
        arr_ptr_ = new T[size_];
        for (unsigned i = 0; i < size_; i++)
        {
            at(i) = second.at(i);
        }
        return *this;
    }

    FlexArray<T> &operator=(FlexArray<T> &&second)
    {
        delete [] arr_ptr_;
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

        T *tmp_ptr = arr_ptr_;

        unsigned new_size = size_ + second.Size();
        arr_ptr_ = new T[new_size];
        unsigned i = 0;
        for (; i < size_; i++)
        {
            at(i) = *(tmp_ptr + i);
        }
        for (unsigned j = 0; i < new_size; j++, i++)
        {
            at(i) = second.at(j);
        }
        delete [] tmp_ptr;
        size_ = new_size;
        return *this;
    }

    FlexArray<T> &operator*=(unsigned n)
    {
        if (n == 1)
        {
            return *this;
        }

        T *tmp_ptr = arr_ptr_;

        unsigned new_size = size_ * n;
        arr_ptr_ = new T[new_size];
        for (unsigned i = 0, j = 0; i < new_size; j++, i++)
        {
            if (j == size_)
            {
                j = 0;
            }

            at(i) = *(tmp_ptr + j);
        }
        delete [] tmp_ptr;
        size_ = new_size;
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    unsigned size_ = 0;
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
    if(first.size_ == 0)
    {
        return second;
    }
    if(second.size_ == 0)
    {
        return first;
    }
    unsigned size = first.Size() + second.Size();
    FlexArray<T> tmp(size);
    unsigned i = 0;
    for (; i < first.Size(); i++)
    {
        tmp.at(i) = first.at(i);
    }
    for (unsigned j = 0; i < size; j++, i++)
    {
        tmp.at(i) = second.at(j);
    }
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