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

int n, m, res = 0;
int map[51][51];
bool visited[51][51];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<pair<int, int>> v;

int bfs(int a, int b)
{
	queue<tuple<int, int, int>> q;

	q.push(make_tuple(a, b, 0));
	visited[a][b] = true;

	while (!q.empty())
	{
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();
		if (map[x][y] == 1) return cnt;
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push(make_tuple(nx, ny, cnt + 1));
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		memset(visited, false, sizeof(visited));
		int x = v[i].first;
		int y = v[i].second;
		int tmp = bfs(x, y);
		if (tmp > res) res = tmp;
	}

	cout << res << "\n";
	return 0;
}