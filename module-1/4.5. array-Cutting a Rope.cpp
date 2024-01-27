#include <iostream>
#include <vector>

using namespace std;

int Sourcelength (vector<int> &array)
{
  int sum = array[0];
  int biggest = 0;
  for (int i = 1; i < array.size(); ++i)
  {
    if(array[i] > array[biggest])
    {
      biggest = i;
    }
    sum += array[i];
  }
  sum -= array[biggest];
  if(array[biggest] > sum) return array[biggest] - sum;
  return array[biggest] + sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> array(n, 0);
  for (int i = 0; i < n; ++i)
  {
    cin >> array[i];
  }
  cout << Sourcelength(array);
  return 0;
}