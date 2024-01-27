#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;

string ToBinary(int len, int value)
{
  string binary(len, '0');
  for (int i = len - 1; i >= 0; --i)
  {
    if (value % 2 == 1)
      binary[i] = '1';
    value /= 2;
  }
  return binary;
}

int main()
{
  int n;
  cin >> n;
  for (int i = (1 << n) - 1; i >= 0; --i)
  {
    cout << ToBinary(n, i) << endl;
  }
  return 0;
}