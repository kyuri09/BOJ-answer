#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;


int main()
{
	int alpha[26];
	string a;
	cin >> a;
	memset(alpha, -1, sizeof(alpha));

	for (int i = 0; i < a.size(); i++)
	{
		
		if (alpha[a[i] - 'a'] != -1) continue;
		alpha[a[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}
	cout << "\n";

	return 0;
}