#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

int subMod (int a, int b, int  c)
{
int res = (a - b) % c;
if (res < 0) {
    res += c;
}
return res;
}
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << subMod(a, b, c);

  return 0;
}