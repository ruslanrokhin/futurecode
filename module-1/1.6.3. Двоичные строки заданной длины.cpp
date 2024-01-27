#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;
int n;
void ToBinary(string &s, int i)
{
  if(i == n - 1)
  {
    s[i] = '0';
    cout << s << endl;
    s[i] = '1';
    cout << s << endl;
  } 
  else
  {
    s[i] = '0';
    ToBinary(s, i + 1);
    s[i] = '1';
    ToBinary(s, i + 1);
  }
}

int main()
{
  cin >> n;
  string s(n,'0');
  ToBinary(s, 0);
  return 0;
}