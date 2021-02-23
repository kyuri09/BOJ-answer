#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int a[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n;

tuple<int,int,int> bfs(int x,int y,int size)
{
	queue<tuple<int, int>> q;
	vector<tuple<int, int, int>> ans;
	int dist[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = -1;
		}
	}
	q.push(make_tuple(x, y));
	dist[x][y] = 0;
	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == -1)
			{
				bool eat = false;
				bool going = false; 
				if (a[nx][ny] == 0)
					going = true;
				else if (a[nx][ny] < size)
				{
					eat = true;
					going = true;
				}
				else if (a[nx][ny] == size)
					going = true;
				if (going)
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_tuple(nx, ny));
					if (eat)
						ans.push_back(make_tuple(dist[nx][ny], nx, ny));

				}
			}
		}
	}
	if (ans.empty())
	{
		return make_tuple(-1, -1, -1);
	}
	sort(ans.begin(), ans.end());
	return ans[0];
}
int main(void)
{

	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 9)
			{
				tie(x, y) = make_pair(i, j);
				a[i][j] = 0;
			}
		}
	}
	int size = 2;
	int ans = 0;
	int exp = 0;
	while (1)
	{
		int nx, ny, dist;
		tie(dist, nx, ny) = bfs(x, y, size);
		if (dist == -1) break;
		a[nx][ny] = 0;
		ans += dist;
		exp += 1;
		if (size == exp)
		{
			size += 1;
			exp = 0;
		}
		tie(x, y) = make_pair(nx, ny);
	}
	cout << ans << endl;
}