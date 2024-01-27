#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
using namespace std;

int isTrue(int p1, int p2, int p3, int p4)
{
  if (p1)
  {
    return 1;
  }
  if(p2 && p4)
  {
    return 1;
  }
  if( !(p2 || p4) && p3)
  {
    return 1;
  }
  return 0;
}

int main()
{
}