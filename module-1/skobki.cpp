#include <iostream>
#include <string>
#include <set>
using namespace std;

bool CorrectBrackets(unsigned brackets, unsigned n)
{
	n *= 2;
	string result(n + 1, ')');
	result[0] = '(';
	result[n] = '\n';
	int sum = 0;
	unsigned discharge = 1;
	for (size_t i = 1; i < n-1; i++)
	{
		discharge <<= 1;
		if (brackets & discharge)
		{
			++sum;
			result[i] = '(';
		}
		else --sum;
		if (sum < 0) return false;
	}
	if (sum == 0) cout << result;
	return (sum == 0);
}

void Skobki(int n)
{
	
	if (1 > n || n > 14) return;
	unsigned length = 1 << (2 * n);
	for (unsigned i = 0; i < length; i++)
	{
		CorrectBrackets(i, n);
	}
}

int main()
{
	int n;
	cin >> n;
	Skobki(n);
	return 0;
}