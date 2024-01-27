#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
using namespace std;

vector<int> step;
vector<int> sum_step;

int Razryad(int n)
{

  size_t i = 0;
  for (size_t size = step.size(); i < size; i++)
  {
    if (n <= sum_step[i])
    {
      return i;
    }
  }

  int stepen = 1, sum = 1;

  if (i > 0)
  {
    stepen = step[i - 1];
    sum = sum_step[i - 1];
    --i;
  }
  else
  {
    step.push_back(stepen);
    sum_step.push_back(sum);
  }
  for (; sum < n; i++)
  {
    stepen *= 3;
    sum += stepen;
    step.push_back(stepen);
    sum_step.push_back(sum);
  }
  return i;
}
void swapper(string &hvost)
{
  for (auto &i : hvost)
  {
    if (i == '1')
    {
      i = '$';
    }
    else if (i == '$')
    {
      i = '1';
    }
  }
}
void replace(string &destination, const string &source)
{
  for (size_t i = 0; i < source.size(); i++)
  {
    destination[i] = source[i];
  }
}

string reverse(string &num_str)
{
  string result(num_str.rbegin(), num_str.rend());
  return (result);
}
string translate(int num10)
{
  if (num10 == 0) return "0";
  bool negative = (num10 < 0);
  if (negative)
    num10 *= -1;
  int valsign = Razryad(num10);
  string num_str(valsign + 1, '0');
  num_str[valsign] = '1';
  num10 -= step[valsign];
  if(num10 == 0 && !negative) return num_str;
  auto hvost = translate(num10);
  if(num10 != 0) replace(num_str, hvost);
  if (negative)
  {
    swapper(num_str);
  }
  return num_str;
}
string Balanced_system(int i){
return reverse(translate(i));
}
int main()
{
  for (int i = -10; i < 20; i++)
  {
    cout << i << " " << Balanced_system(i) << endl;
  }
}