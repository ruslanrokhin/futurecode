#include <iostream>
#include <string>
#include <deque>
#include <cassert>

using namespace std;

deque<int> distribution()
{
    deque<int> tmp;
    int card;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> card;
        tmp.push_back(card);
    }
    return tmp;
}

int who_win(int first, int second)
{

    if (first == 0 && second == 9)
    {
        return 1;
    }
    if (second == 0 && first == 9)
    {
        return 2;
    }
    if (first > second)
    {
        return 1;
    }
    return 2;
}

int main(int argc, char const *argv[])
{
    deque<int> first = distribution(), second = distribution();
    deque<int> *winner;
    int rounds = 0;
    while (rounds < 1000000)
    {
        if (who_win(first.front(), second.front()) == 1)
        {
            winner = &first;
        }
        else
            winner = &second;

        winner->push_back(first.front());
        winner->push_back(second.front());
        first.pop_front();
        second.pop_front();
        rounds++;

        if (second.size() == 0)
        {
            cout << "first" << ' ' << rounds;
            return 0;
        }
        if (first.size() == 0)
        {
            cout << "second" << ' ' << rounds;
            return 0;
        }
    }
    cout << "botva";
};