#include <iostream>
#include <cassert>
#include <vector>

struct UseTheBest
{
    std::vector<unsigned int> array_;
    void p(unsigned int x)
    {
        array_.push_back(x);
    }
    void i(unsigned int ind, unsigned int x)
    {
        if (ind + 1 > array_.size())
        {
            array_.push_back(x);
        }
        else
        {
            auto ind_end = array_.size() - 1;
            array_.push_back(array_[ind_end]);
            for (auto i = ind_end; i > ind; i--)
            {
                array_[i] = array_[i - 1];
            }
            array_[ind] = x;
        }
    }
    void q(unsigned ind)
    {
        std::cout << array_[ind] << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    int q;
    UseTheBest array;
    std::cin >> q;

    for (auto i = 0; i < q; ++i)
    {
        int a, x, ind;
        char c;
        std::cin >> c;
        switch (c)
        {
        case 'p':
            std::cin >> x;
            array.p(x);
            break;
        case 'i':
            std::cin >> ind >> x;
            array.i(ind, x);
            break;
        case '?':
            std::cin >> ind;
            array.q(ind);
            break;
        default:
            break;
        }
    }

    return 0;
}
