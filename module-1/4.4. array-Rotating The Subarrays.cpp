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
  cin >> n;
  vector<int> array(n, 0);
  for (int i = 0; i < n; ++i)
  {
    cin >> array[i];
  }
  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    cin >> l >> r;
    --l;
    --r;
    Sdvig(array, l, r);
  }
  cout << array[0];
  for (int i = 1; i < n; ++i)
  {
    cout << " " << array[i];
  }
  return 0;
}