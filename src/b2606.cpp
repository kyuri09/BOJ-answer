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

bool visited[101];
int c, p, cnt = 0;
int arr[101][101];
int main()
{
	cin >> c >> p;

	for (int i = 0; i < p; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		for (int i = 1; i <= c; i++)
		{
			if (arr[v][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}