#include <iostream>
#include <cmath>
#include <cassert>
#include <unordered_set>
#include <string>
#include <algorithm>
//https://leetcode.com/problems/number-of-1-bits/
using namespace std;

int hammingWeight(uint32_t n)
{
    int sum = 0;
    while (n != 0)
    {
        if(n&1 != 0) ++sum;
        n = n >> 1;
    }
    return sum;
}

int main()
{
  uint32_t n;
  cin >> n;
  hammingWeight(n);
  return 0;
}