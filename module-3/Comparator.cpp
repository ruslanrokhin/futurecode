#include <string>
#include <vector>
struct Assets
{
    std::string holderName;
    std::vector<int> values;
};

class Comparator
{
public:
    bool operator()(const Assets &left, const Assets &right) const
    {
        int left_sum = 0 , right_sum = 0;
        for (size_t i = 0; i < left.values.size(); i++)
        {
            left_sum += left.values[i];
        }
        for (size_t i = 0; i < right.values.size(); i++)
        {
            right_sum += right.values[i];
        }
        if (left_sum == right_sum)
        {
            return (left.holderName < right.holderName);
        }
        return (left_sum < right_sum);
    }
};
