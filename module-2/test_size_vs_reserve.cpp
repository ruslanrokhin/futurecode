#include "log_duration.h"
#include <vector>
#include <random>

using namespace std;

static std::random_device rd;
static std::mt19937 gen(rd());

// генерация случайного числа в диапазоне 1 до 10000
std::uniform_int_distribution<size_t> dis(1, 10000);

inline unsigned int SIZE = 100000000;

int main(int argc, char const *argv[])
{
    vector<int> etalon_(SIZE);
    for (unsigned int i = 0; i < SIZE; i++)
    {
        etalon_[i] = dis(gen);
    }
    {
        LOG_DURATION("reserve");
        vector<int> container_;

        container_.reserve(SIZE);
        for (unsigned int i = 0; i < SIZE; i++)
        {
            container_.push_back(etalon_[i]);
        }
    }

    {
        LOG_DURATION("size");
        vector<int> container_(SIZE);
        for (unsigned int i = 0; i < SIZE; i++)
        {
            container_[i] = etalon_[i];
        }
    }

    {
        int tmp = 0;
        {
            LOG_DURATION("\niterator");
            for (auto i = etalon_.cbegin(); i < etalon_.cend(); i++)
            {
                tmp += *i;
            }
        }
        cout << tmp;
    }

    {
        int tmp = 0;
        {
            LOG_DURATION("\n[i]");
            for (auto i = 0; i < SIZE; i++)
            {
                tmp += etalon_[i];
            }
        }
        cout << tmp;
    }

    return 0;
}
