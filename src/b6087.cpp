#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int mirror[101][101];
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> a(m);
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	for (int i = 0; i < m;i++)
	{
		cin >> a[i];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'C')
			{
				if (sx == -1 && sy == -1)
				{
					sx = i;
					sy = j;
				}
				else
				{
					ex = i;
					ey = j;
				}
			}
		}

	}
	queue<tuple<int, int>> q;
	q.push(make_tuple(sx, sy));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mirror[i][j] = -1;
		}
	}
	mirror[sx][sy] = 0;

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			while(nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (a[nx][ny] == '*') break;
				if (mirror[nx][ny] == -1)
				{
					mirror[nx][ny] = mirror[x][y] + 1;
					q.push(make_tuple(nx, ny));
				}
				nx = nx + dx[i];
				ny = ny + dy[i];
			}
		}
	}
	cout << mirror[ex][ey] -1 << endl;

	return 0;
}