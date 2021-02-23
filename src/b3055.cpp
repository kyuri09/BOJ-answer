#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int r, c;
char map[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int check[50][50];
int time[50][50];
int sx, sy, ex, ey;
queue<tuple<int, int>> w;
void waterbfs()
{
	while (!w.empty())
	{
		int x, y;
		tie(x, y) = w.front();
		w.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (time[nx][ny] == 0 && map[nx][ny] == '.')
			{
				time[nx][ny] = time[x][y] + 1;
				w.push(make_tuple(nx, ny));
			}
		}
	}
}
void bfs()
{
	queue<tuple<int, int>> q;
	q.push(make_tuple(sx, sy));
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if ((map[nx][ny]=='D'||map[nx][ny] == '.') && check[nx][ny] == 0)
			{
				if (time[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_tuple(nx, ny));
				}
				else 
				{
					if (time[nx][ny] > check[x][y] + 1)
					{
						check[nx][ny] = check[x][y] + 1;
						q.push(make_tuple(nx, ny));
					}
				}
			}
		}
	}
}
int main(void)
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (map[i][j] == 'D')
			{
				ex = i;
				ey = j;
			}
			else if (map[i][j] == '*')
			{
				w.push(make_tuple(i, j));
			}
		}
	}

	waterbfs();
	bfs();

	if (check[ex][ey] != 0)
	{
		cout << check[ex][ey] << endl;
	}
	else
	{
		cout << "KAKTUS" << endl;
	}

	
}