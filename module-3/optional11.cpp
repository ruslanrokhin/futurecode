#include <iostream>
#include <cassert>

template <typename T>
class Optional
{
public:
    Optional()
    {
    }
    Optional(const T &value)
    {
        value_ptr_ = new T(value);
    }
    T &Value()
    {
        return *value_ptr_;
    }
    T ValueOr(const T &value)
    {
        if (!(value_ptr_ == nullptr))
        {
            return *value_ptr_;
        }
        return value;
    }
    bool HasValue()
    {
        return (!(value_ptr_ == nullptr));
    }
    void Set(const T &value)
    {
        if (value_ptr_ != nullptr)
        {
            value_ptr_->~T();
            new (value_ptr_) T(value);
        }
        else
        {
        value_ptr_ = new T(value);
        }
    }
    ~Optional()
    {
        if (HasValue())
        {
        delete *value_ptr_;
        }
    }

    T *value_ptr_ = nullptr;
};

int main(int argc, char const *argv[])
{
    Optional<int> opt;
    assert(
        !opt.HasValue());
    opt.Set(115);
    assert(
        opt.HasValue());
    opt.Value() = 911;
    assert(
        opt.Value() == 911);
    return 0;
}
