#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int n, k;
bool visited[100001];
int main()
{
	cin >> n >> k;

	queue<pair<int, int>> q;
	
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty())
	{
		int loc = q.front().first;
		int t = q.front().second;
		q.pop();
		if (loc == k)
		{
			cout << t << "\n";
			break;
		}

		if (loc - 1 >= 0 && !visited[loc - 1])
		{
			q.push(make_pair(loc - 1, t + 1));
			visited[loc - 1] = true;
		}
		if (loc + 1 < 100001 && !visited[loc + 1])
		{
			q.push(make_pair(loc + 1, t + 1));
			visited[loc + 1] = true;
		}
		if (loc * 2 < 100001 && !visited[loc * 2])
		{
			q.push(make_pair(loc * 2, t + 1));
			visited[loc * 2] = true;
		}
	}

	return 0;
}