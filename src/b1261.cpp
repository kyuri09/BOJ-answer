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
vector<string> maze;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int visited[101][101];
int main()
{
	cin >> m >> n;
	
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		maze.push_back(tmp);
	}
	memset(visited, 987654, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	visited[0][0] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (maze[nx][ny] == '1' && visited[nx][ny] > visited[x][y] + 1)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			if (maze[nx][ny] == '0' && visited[nx][ny] > visited[x][y])
			{
				visited[nx][ny] = visited[x][y];
				q.push(make_pair(nx, ny));
			}
		}
	}

	cout << visited[n - 1][m - 1] << "\n";
	return 0;
}