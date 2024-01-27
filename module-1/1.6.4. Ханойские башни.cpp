#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;
void hanoi(int n, int i, int k)
{
  if (n == 1)
    cout << n << ' ' << i << ' ' << k << endl;
  else
  {
    int tmp = 6 - i - k;
    hanoi(n - 1, i, tmp);
    cout << n << ' ' << i  << ' ' << k << endl;
    hanoi(n - 1, tmp, k);
  }
}
int main()
{
  int n;
  cin >> n;
  hanoi(n, 1, 3);
  return 0;
}