#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

#define swap_if(a,b)    if(b < a)   {    a += b;    b = a - b;    a = a - b;  }

void swap_f(int &a, int &b)    {if(b < a)   {    a += b;    b = a - b;    a = a - b;  }}

void Smart_sort(int a, int b, int c)
{
 swap_f(a,b);
 swap_f(b,c);
 swap_f(a,b);
  cout << a << " " << b << " " << c;
}
void Sort(int a, int b, int c)
{
  if (a < b)
  {
    if (a < c)
    {
      if (c < b)
        cout << a << " " << c << " " << b;
      else
        cout << a << " " << b << " " << c;
    }
    else
      cout << c << " " << a << " " << b;
  }
  else
  {
    if (c > a)
      cout << b << " " << a << " " << c;
    else
    {
      if (b < c)
        cout << b << " " << c << " " << a;
      else
        cout << c << " " << b << " " << a;
    }
  }
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  Smart_sort(a, b, c);
  return 0;
}