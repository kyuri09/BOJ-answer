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
	int n;
	cin >> n;
	deque<int> q;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push_front")
		{
			int x;
			cin >> x;
			q.push_front(x);
		}
		else if (cmd == "push_back")
		{
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if (cmd == "pop_front")
		{
			if (!q.empty())
			{
				int tmp = q.front();
				q.pop_front();
				cout << tmp << "\n";
			}
			else cout << "-1" << "\n";
		}
		else if (cmd == "pop_back")
		{
			if (!q.empty())
			{
				int tmp = q.back();
				q.pop_back();
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