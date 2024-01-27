#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    std::multiset<int> st;
    for (auto x : vec)
    {
        st.insert(x);
    }
    vec = std::vector{0};
    for (auto x : st)
    {
        vec.push_back(x);
    }

    for (auto x : vec)
    {
        std::cout << x << " ";
    }
}