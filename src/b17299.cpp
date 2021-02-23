#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int v[1000000];
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
		v[a[i]]++;
	}
	vector<int> ans(a.size(), -1);
	stack<int> s;

	for (int i = 0; i < a.size(); i++)
	{
		while (!s.empty() && v[a[s.top()]] < v[a[i]])
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