#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int CountTheSequenceSteps (unsigned a)
{
  for (int i = 0; i <= 100000; i++)
  {
    if (a == 1) return i + 1;
    if(a % 2 == 1) a = 3 * a + 1;
    else a = a / 2;
  }
  return -1;
}

int main()
{
  int a;
  assert(CountTheSequenceSteps(2) == 2);
  assert(CountTheSequenceSteps(3) == 8);
  cin >> a;
  cout << CountTheSequenceSteps(a);
  return 0;
}