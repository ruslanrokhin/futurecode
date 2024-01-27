#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int Jumper(int k, int n)
{
  if (n < 0)
    n *= -1;
  int jump = n / k;
  int s = jump * k;  // сколько прошла
  int s_ost = n - s; // сколько осталось
  if (s_ost > k / 2)
  {
    s_ost = k - s_ost;
    jump = jump + s_ost + 1;
  }
  else
    jump += s_ost;
  return jump;
}

int main()
{
  int k, n;
  assert(Jumper(5, 10) == 2);
  assert(Jumper(3, 5) == 3);
  assert(Jumper(4, 15) == 5);
  assert(Jumper(710, 760292463) == 1071157);
  cin >> k >> n;
  cout << Jumper(k, n);
  return 0;
}