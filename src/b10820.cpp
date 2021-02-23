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
	
	for (int i = 0; i < 100; i++)
	{
		int a = 0, b = 0, c = 0, d = 0;
		string s;
		getline(cin, s);
		if (s.length() == 0) break;

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= 'a' && s[j] <= 'z') a++;
			else if (s[j] >= 'A' && s[j] <= 'Z') b++;
			else if (s[j] >= '0' && s[j] <= '9') c++;
			else if (s[j] == ' ') d++;
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}

	return 0;
}