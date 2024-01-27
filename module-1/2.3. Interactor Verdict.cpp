#include <iostream>
#include <cassert>

using namespace std;

int Branching(int r, int i, int c)
{
  switch (i)
  {
  case 0:
    if (r != 0)
    {
      return 3;
    }
    else
      return c;
    break;

  case 1:
    return c;
    break;

  case 4:
    if (r != 0)
    {
      return 3;
    }
    else
      return 4;
    break;

  case 6:
    return 0;

    break;
  case 7:
    return 1;

    break;
  default:

    break;
  }
  return i;
}

int main()
{
  int r, i, c;
  assert(Branching(0, 0, 0) == 0);
  assert(Branching(-1, 0, 1) == 3);
  assert(Branching(42, 1, 6) == 6);
  assert(Branching(44, 7, 4) == 1);
  assert(Branching(1, 4, 0) == 3);
  assert(Branching(-3, 2, 4) == 2);
  cin >> r >> i >> c;
  cout << Branching(r, i, c);
  return 0;
}