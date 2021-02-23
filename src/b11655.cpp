#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] + 13 > 'z') s[i] -= 13;
			else s[i] += 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] + 13 > 'Z') s[i] -= 13;
			else s[i] += 13;
		}
	}
	cout << s << "\n";
	return 0;
}