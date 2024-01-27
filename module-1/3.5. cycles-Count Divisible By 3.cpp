#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

int main()
{
  stringstream s;
  string mass;
  int a, result = 0;
  getline(cin, mass);
  s << mass;
  while ( !(s.eof()) )
  {
    s >> a;
    if(a % 3 == 0) ++result;
  }
  cout << result;
  return 0;
  }