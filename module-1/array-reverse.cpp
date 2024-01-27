#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

void ArrayFunc(int value)
{
  vector<int> array(value);
  for (size_t i = 0; i < value; i++)
  {
    cin >> array[i];
  }

  for (int i = value - 1; i >= 0; --i)
  {
    cout << array[i] << " ";
  }
}

int main()
{
  unsigned value;
  cin >> value;
  ArrayFunc(value);
  return 0;
}