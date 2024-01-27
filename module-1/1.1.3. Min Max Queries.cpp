#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
using namespace std;

int main()
{
  int count;
  int n, min, max;
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
      cin >> n;
      if (i == 0)
      {
        min = n;
        max = n;
      }
      if (max < n)
      {
        max = n;
      }
      if (min > n)
      {
        min = n;
      }
    }
    cout << max - min << endl;
  }
}