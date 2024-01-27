#include <iostream>
#include <cassert>
#include <string>

using namespace std;
int CinSearch (int a, int b)
{
  int searh = 0;
  int consolein;
  for(int i = 1; i <= a; ++i)
  {
    cin >> consolein;
    if (consolein == b) searh = i;
  }
  return searh;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << CinSearch(a, b);
  return 0;
  }