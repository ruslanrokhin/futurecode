#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int SumDigits(int n)
{
  int sum = 0;
  while(n != 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main()
{

  assert(SumDigits(999) == 27);

  return 0;
}