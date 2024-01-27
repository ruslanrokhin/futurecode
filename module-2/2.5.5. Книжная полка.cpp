#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    int count, operation, number;
    cin >> count;
    list<int> bookshelf;
    for (size_t i = 0; i < count; i++)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            cin >> number;
            bookshelf.push_front(number);
            break;
        case 2:
            cin >> number;
            bookshelf.push_back(number);
            break;
        case 3:
            cout << bookshelf.front() << endl;
            bookshelf.pop_front();
            break;
        case 4:
        
            cout << bookshelf.back() << endl;
            bookshelf.pop_back();
            break;
        default:
            break;
        }
    }
};