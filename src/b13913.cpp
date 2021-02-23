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
int arr[100001];
vector<int> path;
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
			int idx = loc;
			cout << t << "\n";
			while (idx != n)
			{
				path.push_back(idx);
				idx = arr[idx];
			}
			path.push_back(idx);
			break;
		}

		if (loc - 1 >= 0 && !visited[loc - 1])
		{
			q.push(make_pair(loc - 1, t + 1));
			visited[loc - 1] = true;
			arr[loc - 1] = loc;
		}
		if (loc + 1 < 100001 && !visited[loc + 1])
		{
			q.push(make_pair(loc + 1, t + 1));
			visited[loc + 1] = true;
			arr[loc + 1] = loc;
		}
		if (loc * 2 < 100001 && !visited[loc * 2])
		{
			q.push(make_pair(loc * 2, t + 1));
			visited[loc * 2] = true;
			arr[loc * 2] = loc;
		}
	}

	for (int i = path.size() - 1; i >= 0; i--)
	{
		cout << path[i] << " ";
	}

	return 0;
}