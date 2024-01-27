#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
using namespace std;

int f(int x)
{
  if (x == 1 || x == 2 || x == 3)
  {
    return 1;
  }
  return (f(x - 1) + f(x - 2) + f(x - 3));
}
int main()
{
  int x;
  cin >> x;
  cout << f(x);
}