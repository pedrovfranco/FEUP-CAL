#include "StringSearch.h"

using namespace std;

bool StringSearch::kmp(string pattern, string text){ // i = j, j = k

	vector<int> pi = prefixFunction(pattern);
	int i = 0; //Position in text
	int j = 0; //Position in pattern

	int nP = 0;

	for (i = 0 ; i < text.length();)
	{
		if (pattern[j] == text[i])
		{
			i++;
			j++;

			if (j == pattern.length())
				return true;
		}
		else
		{
			j = pi[j];
			
			if (j < 0)
			{
				i++;
				j++;
			}
		}
	}

	return false;
}

vector<int> StringSearch::prefixFunction(string p){ //q = pos, k = cnd
	vector<int> pi;
	pi.resize(p.length());
	pi[0] = -1;

	int k = 0;
	int q;

	for (q = 1; q < p.length(); q++, k++)
	{
		if (p[q] == p[k])
		{
			pi[q] = pi[k];
			q++;
			k++;
		}
		else
			pi[q] = k;

		k = pi[k];

		while (k >= 0 && p[q] != p[k])
			k = pi[k];
	}

	pi[q] = k;

	return pi;
}


bool cmpi(char ch1, char ch2) // Compares two characters without case sensitivity.
{
	if (ch1 >= 'A' && ch1 <= 'Z')
	{
		ch1 += 'a' - 'A';
	}

	if (ch2 >= 'A' && ch2 <= 'Z')
	{
		ch2 += 'a' - 'A';
	}

	return (ch1 == ch2);
}


int StringSearch::editDistance(string p, string t){
	int n = t.length();
	vector<int> d(n + 1);
	int old, neww;

	for (int j = 0; j <= n; j++)
		d[j] = j;
	int m = p.length();

	for (int i = 1; i <= m; i++)
	{
		old = d[0];
		d[0] = i;

		for (int j = 1; j <= n; j++)
		{
			if (cmpi(p[i - 1], t[j - 1]))
				neww = old;
			else
			{
				neww = min(old, d[j]);
				neww = min(neww, d[j - 1]);
				neww = neww + 1;
			}
			old = d[j];
			d[j] = neww;
		}
	}
	return d[n];
}

double StringSearch::getPercentage(string p, string t)
{
	int size = max(p.length(), t.length());


	return (editDistance(p, t)/(double)size);
}