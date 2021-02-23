#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop")
		{
			if (!q.empty())
			{
				int tmp = q.front();
				q.pop();
				cout << tmp << "\n";
			}
			else cout << "-1" << "\n";
		}
		else if (cmd == "size")
		{
			int s = q.size();
			cout << s << "\n";
		}
		else if (cmd == "empty")
		{
			if (!q.empty()) cout << "0" << "\n";
			else cout << "1" << "\n";
		}
		else if (cmd == "front")
		{
			if (!q.empty()) cout << q.front() << "\n";
			else cout << "-1" << "\n";
		}
		else if (cmd == "back")
		{
			if (!q.empty()) cout << q.back() << "\n";
			else cout << "-1" << "\n";
		}
	}
	return 0;
}