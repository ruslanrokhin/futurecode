#include <iostream>
#include <string>
#include <set>

using namespace std;
inline unsigned Sdvig(unsigned brackets, unsigned i)
{
	unsigned one = 1;
	one <<= i;
	--one;
	return (brackets |= one);
}
bool CorrectBrackets(unsigned &brackets, unsigned n)
{
	int sum = 0;
	unsigned discharge = 1 << (n - 1);
	for (size_t i = n; i > 0; --i)
	{

		if (brackets & discharge)
		{
			++sum;
		}
		else
			--sum;
		if (sum < 0)
		{
			brackets = Sdvig(brackets, i - 1);
			return false;
		}
		discharge >>= 1;
	}
	return sum == 0;
}

void Skobki(int n)
{
	set<unsigned> result;
	static unsigned length = 1 << (n);
	for (unsigned brackets = 0; brackets < length; ++brackets)
	{
		unsigned savebracket = brackets;
		if (CorrectBrackets(brackets, n))
		{
			result.emplace(savebracket);
		}
	}
	const unsigned init_one = 1 << (n - 1);
	for (auto it = result.crbegin(); it != result.crend(); ++it)
	{
		string brackets(n + 1, ')');
		brackets[n] = '\n';
		brackets[0] = '(';
		unsigned discharge = init_one;
		for (size_t i = 1; i < n - 1; i++)
		{
			discharge >>= 1;
			if (*it & discharge)
			{
				brackets[i] = '(';
			}
		}
		cout << brackets;
	}
}

int main()
{
	int n;
	cin >> n;
	n *= 2;
	Skobki(n);
	return 0;
}