#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Print(const vector<int> &terms)
{
  cout << terms.back();
  for (int i = terms.size() - 2; i >= 0; --i)
  {
    cout << ' ' << terms[i];
  }
  cout << endl;
}

bool less_(const vector<int> &right, const vector<int> &left)
{
  for (size_t i = right.size() - 1, j = left.size() - 1; i >= 0 && j >= 0; --i, --j)
  {
    if (right[i] != left[j])
    {
      return (right[i] > left[j]);
    }
  }
  return(right.size() > left.size());
}

void Split(int sum_result, int sum_of_terms, vector<int> &terms, vector<vector<int>> &matrix)
{
  int term_first = sum_result - sum_of_terms;
  if (terms.size() != 0 && terms.back() < term_first)
  {
    term_first = terms.back();
  }
  for (; term_first > 0; --term_first)
  {
    sum_of_terms += term_first;
    terms.push_back(term_first);
    if (sum_of_terms == sum_result)
    {
      matrix.push_back(terms);
    }
    else
    {
      Split(sum_result, sum_of_terms, terms, matrix);
    }
    terms.pop_back();
    sum_of_terms -= term_first;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix;
  vector<int> terms;
  Split(n, 0, terms, matrix);
  sort(matrix.begin(), matrix.end(), less_);
  for (size_t i = 0; i < matrix.size(); ++i)
  {
    Print(matrix[i]);
  }
  return 0;
}