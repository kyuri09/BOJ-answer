#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

int n, m;
int map[1000][1000];
bool check[1000][1000];
int group[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> gs;

void bfs(int sx, int sy)
{
	int g = gs.size();
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	group[sx][sy] = g;
	int cnt = 1;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0 && check[nx][ny] == false)
			{
				q.push(make_pair(nx, ny));
				check[nx][ny] = true;
				group[nx][ny] = g;
				cnt++;
			}
		}
	}
	gs.push_back(cnt);
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
			check[i][j] = false;
			group[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0 && check[i][j] == false)
				bfs(i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				cout << 0;
			else
			{
				set<int> near;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (map[nx][ny] == 0)
					{
						near.insert(group[nx][ny]);
					}
				}
				int ans = 1;
				for (int g : near)
				{
					ans += gs[g];
				}
				cout << ans % 10;
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;

}