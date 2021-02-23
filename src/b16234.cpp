#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, l, r;
int map[50][50];
int sum = 0;
int res = 0;
int v[50][50];
vector<pair<int, int>> pos;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1)
			continue;

		if (v[nx][ny] != 0)
			continue;

		if (l <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= r)
		{
			sum += map[nx][ny];
			v[nx][ny] = 1;
			pos.push_back(make_pair(nx, ny));
			dfs(nx, ny);
		}
	}
}
int main(void)
{
	cin >> n >> l >> r;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	while (1)
	{
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				v[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[i][j] != 0)
					continue;

				sum = map[i][j];
				v[i][j] = 1;

				pos.clear();
				pos.push_back(make_pair(i, j));
				dfs(i, j);

				if (pos.size() == 1) continue;

				flag = 1;
				sum = sum / pos.size();

				for (int k = 0; k < pos.size(); k++)
				{
					map[pos[k].first][pos[k].second] = sum;
				}

			}
		}
		if (flag == 0) break;

		res++;
		
	}

	cout << res << endl;

	return 0;
}