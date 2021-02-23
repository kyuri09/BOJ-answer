#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int n;
int ans = 0;
char alpha[256];

int sum(vector<string> &str,vector<char> &letters,vector<int> &num)
{
	int m = letters.size();
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		alpha[letters[i]] = num[i];		//alpha[i]=아스키코드로 i의 값
	}
	for (string s : str)
	{
		int res = 0;
		for (char x : s)			//단어 1개 
		{
			res = res * 10 + alpha[x];		
		}
		result += res;
	}
	return result;
}
int main(void)
{
	cin >> n;

	vector<int> num;
	vector<string> str(n);		//단어
	vector<char> letters;		//알파벳

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (char x : str[i])
		{
			letters.push_back(x);
		}
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()),letters.end());

	int m = letters.size();

	for (int i = 9; i > 9 - m; i--)
	{
		num.push_back(i);
	}

	do
	{
		int now = sum(str, letters, num);
		if (ans < now) ans = now;
	} while (prev_permutation(num.begin(), num.end()));
	
	cout << ans << endl;

	return 0;
}