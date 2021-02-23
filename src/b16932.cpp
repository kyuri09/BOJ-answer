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

int n, m;
int map[1001][1001];
int dist[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				dist[i][j] = 1;
		}
	}
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	bool flag = false;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == 1)
			{
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = 1;
				flag = true;
			}
			
		}
	}
}