#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dist[101];
int con[101];
int n, m;

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i <= 100; i++)
	{
		con[i] = i;
		dist[i] = -1;
	}
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		con[x] = y;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		con[x] = y;
	}

	queue<int>q;
	dist[1] = 0;
	q.push(1);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int y = x + i;
			if (y > 100) continue;
			y = con[y];
			if (dist[y] == -1)
			{
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}

	cout << dist[100] << endl;

	return 0;
}
