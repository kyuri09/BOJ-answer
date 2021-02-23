#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	queue<int> q1, q2;

	for (int i = 1; i <= n; i++)
	{
		q1.push(i);
	}

	
	while (!q1.empty())
	{
		int x;
		for (int i = 0; i < k-1; i++)
		{
			x = q1.front();
			q1.pop();
			q1.push(x);
		}
		int y = q1.front();
		q1.pop();
		q2.push(y);
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++)
	{
		int tmp;
		tmp = q2.front();
		q2.pop();
		cout << tmp << ", ";
	}
	int tmp2 = q2.front();
	cout << tmp2 << ">\n";

	return 0;
}