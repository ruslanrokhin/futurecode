#include <iostream>
#include <cassert>
#include <string>

using namespace std;

string Cycle(int a, int b)
{
  string result = "0 0";
  int x, tmp;
  for (int y = -10000; y <= 10000; ++y)
  {
    tmp = (1 - b * y) / a;
    if (-10000 <= tmp && tmp <= 10000 && (1 - b * y) % a == 0)
    {
      x = tmp;
      result = to_string(x) + " " + to_string(y);
      return result;
    }
  }
  return result;
}

int main()
{
  int a, b;
  // cout << Cycle(2, 3) << endl;
  // cout << Cycle(4, 6)  << endl;
  // cout << Cycle(100, 51);
  cin >> a >> b;
  cout << Cycle(a, b);
  return 0;
}