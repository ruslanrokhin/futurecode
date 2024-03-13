#include <iostream>

class ExceptionLess : public std::exception
{
};
class ExceptionGreater : public std::exception
{
};
class ExceptionEqual : public std::exception
{
};

class BlackBox
{
    int key_;

public:
    BlackBox(int key) : key_(key) {}
    void GuessNumber(int x) const
    {
        if (x < key_)
        {
            throw ExceptionGreater();
        }
        if (x > key_)
        {
            throw ExceptionLess();
        }
        throw ExceptionEqual();
    }
};

int guess(const BlackBox &box)
{
    int result = 50, min = 1, max = 100;
    while (true)
    {
        try
        {
            box.GuessNumber(result);
        }
        catch (ExceptionLess)
        {
            max = result -1;
            result = min + (max - min) / 2;
        }
        catch (ExceptionGreater)
        {
            min = result + 1;
            result = min + (max - min) / 2;
        }
        catch (ExceptionEqual)
        {
            return result;
        }
    }
}
int main(int argc, char const *argv[])
{
    BlackBox binare(13);
    std::cout << std::endl << guess(binare) << std::endl;
    return 0;
}
