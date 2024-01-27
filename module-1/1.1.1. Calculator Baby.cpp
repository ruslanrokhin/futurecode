#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
using namespace std;
void caculator()
{
  int a, b;
  char sign;
  cin >> a >> sign >> b;
  switch (sign)
  {
  case '+':
    cout << (a + b);
    break;

  case '-':
    cout << (a - b);
    break;

  case '*':
    cout << (a * b);
    break;

  case '/':
    if (a % b != 0)
    {
      cout << "No";
    }
    else
    {
      cout << (a / b);
    }
    break;

  default:
    break;
  }
}

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    caculator();
    cout << endl;
  }
}