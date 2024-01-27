#include <vector>
#include <iostream>

using namespace std;

void foo(vector<int> &v)
{
    cout << &v << endl;
    cout << v.size() << endl;
}

void Fibonachi(int n)
{
    int f0 = 0;
    int f1 = 1;
    int f;
    for (int i = 1; i < n; i++)
    {
        f = f1 + f0;
        f0 = f1;
        f1 = f;
        cout << f << endl;
    }
}

int recFibonachi(int n)
{

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return recFibonachi(n - 1) + recFibonachi(n - 2);
}
ostream &operator<<(ostream &out, const vector<int> &n)
{
    out << n[0];
    for (int i = 1; i < n.size(); i++)
    {
        out << " " << n[i];
    }
    return out;
}
void Sort(vector<int> &n)
{
    bool restart;
    do
    {
        restart = false;
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] < n[i - 1])
            {
                swap(n[i], n[i - 1]);
                restart = true;
            }
        }
    } while (restart);
}
int main()
{
    vector<int> n = {4, 5, 3, 1, 2, 8, 6, 7};
    cout << n << endl;
    Sort(n);
    cout << n;
}