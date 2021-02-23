#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
int board[201][201];

int main(void)
{
	cin >> n;
	int r1, c1, r2, c2;
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			board[i][j] = -1;
		}
	}
	cin >> r1 >> c1 >> r2 >> c2;
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	board[r1][c1] = 0;

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n || ny>n)
			{
				continue;
			}
			else if (board[nx][ny] == -1)
			{
				q.push(make_pair(nx, ny));
				board[nx][ny] = board[x][y] + 1;
			}
		}
	}
	cout << board[r2][c2] << endl;
}