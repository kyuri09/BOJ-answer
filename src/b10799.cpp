#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	string a;
	cin >> a;
	int cnt = 0;
	deque<char> q;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(' && a[i + 1] == ')')
		{
			cnt += q.size();
			i += 1;
		}
		else if (a[i] == '(')
		{
			q.push_front(a[i]);
		}
		else
		{
			cnt++;
			q.pop_front();
		}
	}
	cout << cnt << "\n";

	return 0;
}