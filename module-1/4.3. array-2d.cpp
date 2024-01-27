#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<int>> table(n, vector<int>(m, 0));
  vector<int> sum(m, 0);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> table[i][j];
      sum[j] += table[i][j];
    }
  }
  cout << sum[0];
  for (int i = 1; i < m; i++)
  {
    cout << " " << sum[i];
  }

  return 0;
}
