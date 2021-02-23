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

int k, w, h;
int dx[] = { -1,-2,-2,-1,2,1,2,1 };
int dy[] = { -2,-1,1,2,1,2,-1,-2 };
int ddx[] = { -1,0,1,0 };
int ddy[] = { 0,1,0,-1 };
int map[201][201];
bool dist[201][201][201];
int main()
{
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
		}
	}
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 0));
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, kk, cnt;
		tie(x, y, kk, cnt) = q.front();
		q.pop();
		if (x == h - 1 && y == w - 1)
		{
			cout << cnt << "\n";
			return 0;
		}
		if (kk < k)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

				if (map[nx][ny] == 0 && !dist[nx][ny][kk + 1])
				{
					dist[nx][ny][kk + 1] = true;
					q.push(make_tuple(nx, ny, kk + 1, cnt + 1));
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + ddx[i];
			int ny = y + ddy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

			if (map[nx][ny] == 0 && !dist[nx][ny][kk])
			{
				dist[nx][ny][kk] = true;
				q.push(make_tuple(nx, ny, kk, cnt + 1));
			}
		}
	}

	cout << "-1\n";
	return 0;
}