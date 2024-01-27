#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, vz, vp;
  cin >> n;
  for (int i = 0; i <= n; i++)
  {
    vz = 2 * i - 1;
    vp = (2 * n - 1) - vz;
    for (int i = 0; i < n; i++)
    {
      for (int i = 0; i < vp / 2; i++)
        cout << " ";
      for (int i = 0; i < vz; i++)
        cout << "*";
      for (int i = 0; i < vp / 2; i++)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}