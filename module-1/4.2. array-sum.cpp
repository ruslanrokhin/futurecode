#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

void Input(int n)
{
  unsigned q, r, l;
  vector<int> array(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  cin >> q;
  for (unsigned i = 0; i < q; ++i)
  {
    cin >> l >> r;
    unsigned sum = 0;
    for (unsigned i = l-1; i < r; i++)
    {
      sum += array[i];
    }
    cout << sum << endl;
  }
  
}

int main()
{
  unsigned n;
  cin >> n;
  Input(n);
  return 0;
}