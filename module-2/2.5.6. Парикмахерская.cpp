#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <list>
#include <fstream>

using namespace std;

struct Visitor
{
    int hours, minutes, angry_step;
    int come_in()
    {
        return (minutes + hours * 60);
    }
};

void print(int time)
{
    cout << time / 60 << ' ' << time % 60 << endl;
}

int main(int argc, char const *argv[])
{
    // if(argc > 1)
    // fstream input("input.txt");

    Visitor tmp;
    int count, time_free = 0, come_in;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        cin >> tmp.hours >> tmp.minutes >> tmp.angry_step;
        come_in = tmp.come_in();
        if (i == 0)
            time_free = tmp.come_in();
        if (come_in >= time_free)
        {
            time_free = come_in + 20;
            print(time_free);
        }
        else
        {
            if ((time_free - come_in + 19) / 20 <= tmp.angry_step)
            {
                time_free += 20;
                print(time_free);
            }
            else
            {
                print(come_in);
            }
        }
    }
}; 