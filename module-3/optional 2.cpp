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

    Optional(const Optional &another)
    {
        value_ptr_ = new T(another.Value());
    }
    T &Value() 
    {
        return *value_ptr_;
    }
    const T &Value() const
    {
        return *value_ptr_;
    }
    Optional &operator=(const Optional &another)
    {
        Set(another.Value());
        return *this;
    }
    Optional &operator=(const T &value)
    {
        Set(value);
        return *this;
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

    T *Address()
    {
        return value_ptr_;
    }
    const T *Address() const
    {
        return value_ptr_;
    }
    ~Optional()
    {
        if (HasValue())
        {
            delete value_ptr_;
        }
    }

    T *value_ptr_ = nullptr;
};

int main(int argc, char const *argv[])
{
    const Optional<int> cref;
    // auto aaa = ;
    assert((std::is_assignable_v<decltype(cref.Value()), int> == false));
    assert((std::is_assignable_v<decltype(cref.Address()), int> == false));
    Optional<int> opt;
    assert(
        !opt.HasValue());
    opt.Set(115);
    assert(
        opt.HasValue());
    opt.Value() = 911;
    assert(
        opt.Value() == 911);
    {
        Optional<int> opt2 = opt;
        assert(
            opt2.Value() == 911);
    }
    {
        Optional<int> opt2(opt);
        assert(
            opt2.Value() == 911);
    }
    {
        Optional<int> opt2(10);
        assert(opt2.Value() == 10);
        opt2 = opt;
        assert(opt2.Value() == 911);
        opt2 = 42;
        assert(opt2.Value() == 42);
    }
    return 0;
}
