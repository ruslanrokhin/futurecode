#include <cassert>
#include <string>
#include <iostream>
#include <set>

template <typename T>
T min (T a, T b)
{
  if((a) < (b))
  return (a);
  else return (b);
}
template <typename T>
T max (T a, T b)
{
  if((a) > (b))
  return (a);
  else return (b);
}
template <typename T>
T abs (T a)
{
  if(a < 0)
  return (-1 * (a));
  else return (a);
}

int main()
{
  assert ( min(3 + 2, 5 + 4) == 5);
  assert ( max(3 + 2, 5 + 4) == 9);
  assert ( abs(2 - 1) == 1);
}