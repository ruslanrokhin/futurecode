#include <iostream>
#include <string>

struct PlusOne
{
    static void plusone(std::string &num_)
    {
        bool ten = false;
        auto j = num_.begin();
        for (; j != num_.end() && *j == '9'; j++)
        {
        }
        if (j == num_.end())
        {
            num_ = std::string(num_.size() + 1,'0');
            num_[0] = '1';
            return;
        }

        for (auto i = num_.rbegin(); i != num_.rend(); i++)
        {
            char letter = *i;
            int digit = letter - '0' + 1;
            *i = '0' + digit % 10;
            if (digit < 10)
            {
                return;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    std::string num;
    std::cin >> num;
    PlusOne::plusone(num);
    std::cout << num;
}
