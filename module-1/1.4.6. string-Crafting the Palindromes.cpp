#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

extern int x, y;



int Palindrome (string &word)
{
  int length = word.size() - 1, sum = 0;
for (size_t i = 0; i < word.size() / 2; i++)
{
  if (word[i] != word[length - i]) ++sum;
}
return sum;
}

int main()
{
string word;
cin >> word;
cout << Palindrome(word);
  return 0;
}