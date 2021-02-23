#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;

int f, s, g, u, d;
bool visitied[1000001];
int main()
{
	cin >> f >> s >> g >> u >> d;

	queue<pair<int, int>> q;

	visitied[s] = true;
	q.push(make_pair(s, 0));

	bool flag = false;
	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == g)
		{
			flag = true;
			cout << cnt << "\n";
			break;
		}
		if (now + u <= f && !visitied[now + u])
		{
			visitied[now + u] = true;
			q.push(make_pair(now + u, cnt + 1));
		}
		if (now - d > 0 && !visitied[now - d])
		{
			visitied[now - d] = true;
			q.push(make_pair(now - d, cnt + 1));
		}
	}

	if (!flag)
	{
		cout << "use the stairs\n";
	}
	return 0;
}