#include <iostream>
#include <cmath>
#include <cassert>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int SumOfNum(int n)
{
  int sum = 0;
  while (n != 0)
  {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }
  return sum;
}
bool isHappy(int n)
{
  unordered_set<int> results;
  results.insert(SumOfNum(n));
  int result = SumOfNum(n); 
  while (true)
  {
    if (result == 1)
      return 1;
    result = SumOfNum(result);
    cout << result << endl;
    if(results.count(result)) return 0;
    results.insert(result);
  }
}

int main()
{
  int n;
  cin >> n;
  cout << isHappy(n);
  return 0;
}