#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int alpha[26];
int main()
{
	string a;
	cin >> a;

	for (int i = 0; i < a.size(); i++)
	{
		alpha[a[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}
	cout << "\n";

	return 0;
}