#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <list>
#include <set>

using namespace std;

/*int check(const vector<int> &N, const vector<int> &M)
{
    vector<int> suspicious;
    int list = 0;
    bool is_suspicious = false;
    int N_size = N.size(), M_size = M.size();
    for (size_t i = 0; i < N_size; i++)
    {
        for (size_t j = 0; j < M_size; j++)
        {
            if (N[i] == M[j])
            {
                for (size_t j = 0; j < suspicious.size(); j++)
                {
                    if (N[i] == suspicious[j])
                    {
                        is_suspicious = true;
                    }
                }
                if (!(is_suspicious))
                {
                    list++;
                    suspicious.push_back(N[i]);
                    is_suspicious = false;
                }
            }
        }
    }
    return list;
}
int main(int argc, char const *argv[])
{
    int count_N, count_M, tmp;
    vector<int> N, M;
    cin >> count_N;
    for (size_t i = 0; i < count_N; i++)
    {
        cin >> tmp;
        N.push_back(tmp);
    }
    cin >> count_M;
    for (size_t i = 0; i < count_M; i++)
    {
        cin >> tmp;
        M.push_back(tmp);
    }
    cout << check(N, M);
};*/

void insert_set(set<int> &user_list)
{
    int count, tmp;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        cin >> tmp;
        user_list.insert(tmp);
    }
}
int main(int argc, char const *argv[])
{
    int count = 0;
    set<int> N, M;
    insert_set (N);
    insert_set(M);
    for (auto i = N.begin(); i != N.end(); i++)
    {
        if (M.find(*i) != M.end())
        {
            count++;
        }
    }
    cout << count;
    return 0;
}
