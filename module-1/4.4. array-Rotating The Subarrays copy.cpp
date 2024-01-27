#include <iostream>
#include <vector>

using namespace std;

void Sdvig(vector<int> &array, int l, int r)
{
  int buffer = array[r];
  for (int i = r; i > l; --i)
  {
    array[i] = array[i - 1];
  }
  array[l] = buffer;
}

int main()
{
  int n, l, r, k;
  n = 100000;
  vector<int> array(n, 0);
  for (int i = 0; i < n; ++i)
  {
    array[i] = i;
  }
  k = 1;

  Sdvig(array, 0, 99999);
  cout << array[0];
  for (int i = 1; i < n; ++i)
  {
    cout << " " << array[i];
  }
  return 0;
}