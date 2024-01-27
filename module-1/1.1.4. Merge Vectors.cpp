#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
//using namespace std;

std::vector<int> merge(std::vector<int> a, std::vector<int> b)
{
  std::vector<int> result(a.begin(), a.end());
  for (auto i = b.begin(); i != b.end(); i++)
  {
    result.push_back(*i);
  }
  return result;
}

int main()
{
  std::vector<int> a = {1,2,3};
  std::vector<int> b = {4,5, 6};
  auto result = merge(a, b);
}