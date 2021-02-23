/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	deque<int> q;
	bool flag = false;
	bool flag2 = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		flag = false;
		flag2 = false;

		int tmp = q.front();
		q.pop_front();
		for (int j = 0; j < q.size(); j++)
		{
			if (tmp < q.front() && !flag)
			{
				cout << q.front() << " ";
				int x = q.front();
				q.pop_front();
				q.push_back(x);
				flag = true;
				flag2 = true;

			}
			else 
			{
				int tmp2 = q.front();
				q.pop_front();
				q.push_back(tmp2);
				flag2 = true;
			}

		}
		if (flag2&&!flag)
		{
			cout << "-1 ";
		}
	}
	cout << "-1\n";

	return 0;
}
*/	////시간초과

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<int> ans(a.size(), -1);
	stack<int> s;

	for (int i = 0; i < a.size(); i++)
	{
		while (!s.empty() && a[s.top()] < a[i])
		{
			ans[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}