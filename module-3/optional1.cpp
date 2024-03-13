#include <iostream>
#include <cassert>

template <typename T>
class Optional
{
public:
    Optional()
    {
    }
    Optional(const T &value) : hasvalue_(true)
    {
        *value_ptr_ = new T(value);
    }
    T &Value()
    {
        return *value_ptr_;
    }
    T ValueOr(const T &value)
    {
        if (hasvalue_)
        {
            return *value_ptr_;
        }
        return value;
    }
    bool HasValue()
    {
        return hasvalue_;
    }
    void Set(const T &value)
    {
        if (hasvalue_)
        {
            delete value_ptr_;
        }
        else
        {
            hasvalue_ = true;
        }
        value_ptr_ = new T(value);
    }
    ~Optional()
    {
        delete value_ptr_;
    }
    bool hasvalue_ = false;
    T *value_ptr_ = {};
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
