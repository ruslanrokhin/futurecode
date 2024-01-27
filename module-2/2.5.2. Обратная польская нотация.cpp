#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int kurva(const string &input)
{
    vector<int> stack;
    for (auto i = 0; i < input.size(); i++)
    {
        int last = stack.size() - 1, tmp = 0;
        if (input[i] == ' ')
        {
            i++;
        }
        switch (input[i])
        {
        case '*':
            tmp = stack[last - 1] * stack[last];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);
            break;
        case '/':
            tmp = stack[last - 1] / stack[last];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);
            break;
        case '-':
            tmp = stack[last - 1] - stack[last];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);
            break;
        case '+':
            tmp = stack[last - 1] + stack[last];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);
            break;
        default:
            while (input[i] != ' ')
            {
                tmp = tmp * 10 + input[i] - '0';
                i++;
            }
            stack.push_back(tmp);
            break;
        }
    }
    return stack.back();
}

int main(int argc, char const *argv[])
{
    string input;
    // assert(kurva("1 2 + 3 4 + *") == 21);
    // assert(kurva("1 3 * 20 4 / 7 3 - * +") == 23);
    getline(cin, input);
    cout << kurva(input);
};