#include <bits/stdc++.h>
using namespace std;

void prefix_suffix_array(int n, string p, int arr[])
{
	if (n == 1)
	{
		arr[0] = 0;
		return;
	}
	int i = 1, j = 0;
	arr[0] = 0;
	while (i != n)
	{
		if (p[i] != p[j])
		{
			if (j == 0)
			{
				arr[i] = 0;
				i++;
			}
			else
			{
				j = arr[j-1];
				if (p[i] == p[j])
				{
					arr[i] = arr[j]+1;
					i++; j++;
				}
			}
		}
		else
		{
			arr[i] = arr[i-1]+1;
			i++; j++;
		}
	}
}

void substring_search(string text, string pattern, int arr[])
{
	int k = 0, index;
	for (int i = 0; i < text.length();)
	{
		if (text[i] == pattern[k])
		{
			i++;
			k++;
			if (k == pattern.length())
			{
				cout << "substring found at index - " << i - k << endl;
				return;
			}
		}
		else if (text[i] != pattern[k] && k == 0)
			i++;
		else
			k = arr[k-1];
	}
	cout << "substring not found" << endl;
}

int main()
{
	string text, pattern;
	text = "ababcaababcaabc";
	pattern = "ababcaabc";

	int n = pattern.length();
	int temp_arr[n+1];

	prefix_suffix_array(n, pattern, temp_arr);

	//for (int i = 0; i < n; i++)
		//cout << temp_arr[i] << " ";

	substring_search(text, pattern, temp_arr);
}

