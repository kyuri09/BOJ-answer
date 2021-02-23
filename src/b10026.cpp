#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int n;
bool check[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool can(bool blind,char from, char to)
{
	if (from == to) return true;
	if (blind)
	{
		if (from == 'G' && to == 'R') return true;
		if (from == 'R' && to == 'G') return true;
	}
	return false;
}
int bfs(vector<string>& board,bool blind)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false)
			{
				ans += 1;
				queue<tuple<int, int>> q;
				q.push(make_tuple(i, j));
				check[i][j] = true;
				while (!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (check[nx][ny]) continue;
						if (can(blind, board[x][y], board[nx][ny]))
						{
							check[nx][ny] = true;
							q.push(make_tuple(nx, ny));
						}
					}
				}
			}
		}
	}
	return ans;
}
int main(void)
{
	cin >> n;

	vector<string> board(n);

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	cout << bfs(board,false) << " " << bfs(board, true) << endl;

	return 0;
}