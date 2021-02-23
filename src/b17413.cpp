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
	bool flag = false;
	string a;
	getline(cin, a);
	a += '\n';
	deque<char> q;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '<')
		{
			while (!q.empty())
			{
				cout << q.front();
				q.pop_front();
			}
			cout << "<";
			flag = true;
		}
		else if (a[i] == '>')
		{
			cout << ">";
			flag = false;
		}
		else if (flag)
		{
			cout << a[i];
		}
		else if (a[i] == ' ' || a[i] == '\n')
		{
			while (!q.empty())
			{
				cout << q.front();
				q.pop_front();
			}
			cout << " ";
		}
		else
			q.push_front(a[i]);
	}


	return 0;
}