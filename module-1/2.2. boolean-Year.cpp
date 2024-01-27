#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool boolean_Year (int  y)
{
  if (y % 100 == 0)
  {
    if(y % 400 == 0) return 1;
  }
  else if(y % 4 == 0) return 1;
 
  return 0;
 }

int main()
{
  int y;
  assert(boolean_Year(1600) == 1);
  assert(boolean_Year(1700) == 0);
  assert(boolean_Year(2021) == 0);
  assert(boolean_Year(2024) == 1);
  cin >>y;
  cout << boolean_Year(y);
  return 0;
}