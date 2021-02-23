#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

bool check[8][8][9];
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };

int main(void)
{
	vector<string> a(8);
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	queue<tuple<int, int, int>> q;
	check[7][0][0] = true;
	q.push(make_tuple(7, 0, 0));
	bool flag = false;
	while (!q.empty())
	{
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();
		if (x == 0 && y == 7) flag = true;
		for (int i = 0; i < 9; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = min(t + 1, 8);
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
			if (nx - t -1>= 0 && a[nx - t-1][ny] == '#') continue;
			if (check[nx][ny][nt] == false)
			{
				check[nx][ny][nt] = true;
				q.push(make_tuple(nx, ny, nt));
			}
		}
	}
	if (flag==true)
	{
		cout << 1 << endl;
	}
	else cout << 0 << endl;
}