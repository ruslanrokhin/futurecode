#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

int retranslation (int from, map<int, int> &radio)
{
    std::map<int, int>::iterator tmp = radio.find(from);
    int to = from;
    while(tmp != radio.end())
    {
        to = tmp->second;
        tmp = radio.find(tmp->second);
    }
    return to;
}

int main(int argc, char const *argv[])
{
    int count, from, to;
    map<int, int> radio;
    cin >> count;
    for (auto i = 0; i < count - 1; i++)
    {
        cin >> from >> to;
        radio.insert({from, to});
    }
    cin >> from;
    cout << retranslation(from, radio);    
};