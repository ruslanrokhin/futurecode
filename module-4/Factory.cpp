#include <unordered_set>

struct HashSwap;
class Factory;
class SwapPair
{
    int first_ = 0, second_ = 0;
    Factory * factory_ = nullptr;

public:
    size_t GetHash() const
    {
        return 13 * first_ + 7 * second_;
    }
    SwapPair()
    {
    }
    SwapPair(int first, int second, Factory * factory = nullptr) : first_(first), second_(second) , factory_(factory)
    {
        if (second_ > first_)
        {
            first_ += second_;
            second_ = first_ - second_;
        }
    }
    SwapPair(const SwapPair &tmp) : first_(tmp.first_), second_(tmp.second_), factory_(tmp.factory_)
    {
    }
    Factory &GetFactory() const
    {
        return *factory_;
    }
    bool operator==(const SwapPair &another) const
    {
        return (first_ == another.first_ && second_ == another.second_);
    }
};

class Factory
{
public:
    // Factory()
    // {
    // }
    std::unordered_set<SwapPair, HashSwap> pair_bank_;
    SwapPair &GetPair(int first, int second)
    {
        //SwapPair tmp(first, second, this);
        // tmp.factory_ = this;
        auto set_pair = pair_bank_.insert({first, second, this});
        return (*set_pair.first);
    }
    int Size() const;
};

struct HashSwap
{
    size_t operator() (const SwapPair &sp) const
    {
        return sp.GetHash();
    }
};

int
main(int argc, char const *argv[])
{
     std::unordered_set<SwapPair, HashSwap> pair_bank_;

    // Factory factory;
    // auto pair = factory.GetPair(1, 2);

    return 0;
}
