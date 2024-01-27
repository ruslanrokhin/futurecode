#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

double Koren(double a, double b, double c, bool second);

string Out(double a, double b, double c)
{
  return to_string(Koren(a, b, c, true)) + "\n" + to_string(Koren(a, b, c, false));
}
double Koren(double a, double b, double c, bool second)
{
  if (a < 0)
  {

    return (-b + (second ? 1 : -1) * sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
  }
  else
  {
    return (-b + (second ? -1 : 1) * sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
  }
}

int main()
{
  cout << std::setprecision(5);
  cout << std::fixed;
  double a, b, c;
  cin >> a >> b >> c;
  cout << Koren(a, b, c, true) << "\n" << Koren(a, b, c, false);
  return 0;
}