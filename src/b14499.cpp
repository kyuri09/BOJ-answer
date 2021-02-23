#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int x, y;
int map[20][20];
int dice[6];
int dir[1001];

void rot(int d)
{
	int tmp;
	if (d == 1)		//오른쪽
	{
		tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[5];
		dice[5] = tmp;
	}
	else if (d == 2)	//왼쪽
	{
		tmp = dice[3];
		dice[3] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (d == 3)		//위
	{
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
	}
	else if (d == 4)		//아래
	{
		tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[0];
		dice[0] = tmp;
	}
}
int move(int dir)
{
	if (dir == 1)		//동
	{	
		if (y + 1 > m - 1) return -1;
		y = y + 1;
		rot(dir);
		if (map[x][y] == 0)
		{
			map[x][y] = dice[3];
		}
		else
		{
			dice[3] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (dir == 2)		//서
	{
	
		if (y -1 < 0) return -1;
		y = y - 1;
		rot(dir);
		if (map[x][y] == 0)
		{
			map[x][y] = dice[3];
		}
		else
		{
			dice[3] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (dir == 3)		//북
	{
		
		if (x-1 < 0) return -1;
		x = x - 1;
		rot(dir);
		if (map[x][y] == 0)
		{
			map[x][y] = dice[3];
		}
		else
		{
			dice[3] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (dir == 4)		//남
	{
		
		if (x+1 > n - 1) return -1;
		x = x + 1;
		rot(dir);
		if (map[x][y] == 0)
		{
			map[x][y] = dice[3];
		}
		else
		{
			dice[3] = map[x][y];
			map[x][y] = 0;
		}
	}
	return 1;
}
int main(void)
{
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> dir[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (move(dir[i]) == -1) continue;
		else
			cout << dice[1] << endl;
	}
	return 0;
}