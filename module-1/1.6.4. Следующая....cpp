#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &out, vector<int> &v)
{
  auto it = v.begin();
  out << *it;
  it++;
  for (; it < v.end(); it++)
  {
    out << " " << *it;
  }
  return out;
}
void Permlate(vector<int> sequence)
{
  for (auto it_l = sequence.rbegin(); it_l != sequence.rend(); ++it_l)
  {
    for (auto it_r = sequence.rbegin(); it_r != it_l; ++it_r)
    {
      if (*it_l < *it_r)
      {
        swap(*it_r, *it_l);+
        auto tmp = it_l;
        sort(tmp.base(), sequence.end());
        cout << sequence << endl;
        return;
      }
    }
  }
  sort(sequence.begin(), sequence.end());
  cout << sequence << endl;
  return;
}

int main()
{
  int n;
  cin >> n;
  vector<int> sequence(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> sequence[i];
  }
  Permlate(sequence);
  return 0;
}