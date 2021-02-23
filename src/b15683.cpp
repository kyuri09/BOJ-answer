#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> cctv;
vector<pair<int, int>> loc;
int map[8][8];
int ans = 9999;

void copy(int(*tmpmap)[8], int(*map)[8])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmpmap[i][j] = map[i][j];
		}
	}
}
void spread(int d, int x, int y)
{
	if (d == 0)			
	{
		x = x - 1;
		if (x < 0) return;
		if (map[x][y] == 6) return;
		map[x][y] = -1;
		spread(0, x, y);
	}
	else if (d == 1)
	{
		y = y + 1;
		if (y > m-1) return;
		if (map[x][y] == 6) return;
		map[x][y] = -1;
		spread(1, x, y);
	}
	else if (d == 2)
	{
		x = x + 1;
		if (x > n-1) return;
		if (map[x][y] == 6) return;
		map[x][y] = -1;
		spread(2, x, y);
	}
	else if (d == 3)
	{
		y = y - 1;
		if (y < 0) return;
		if (map[x][y] == 6) return;
		map[x][y] = -1;
		spread(3, x, y);
	}
}
void check()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) count++;
		}
	}
	if (ans > count) ans = count;
}
void dfs(int count)
{

	int tmpmap[8][8];

	if (count == cctv.size())
	{
		check();
		return;
	}

	int num = cctv[count];
	int x = loc[count].first;
	int y = loc[count].second;

	if (num == 1)			//1번 cctv 
	{
		for (int i = 0; i < 4; i++)		//상, 하, 좌,우
		{
			copy(tmpmap, map);
			spread(i, x, y);			
			dfs(count + 1);
			copy(map, tmpmap);
		}
	}
	else if (num == 2)	//2번 cctv
	{
		for (int i = 0; i < 2; i++)		//상하, 좌우 만 가능
		{
			copy(tmpmap, map);
			spread(i, x, y);		
			spread(i + 2, x, y);
			dfs(count + 1);
			copy(map, tmpmap);
		}
	}
	else if (num == 3)		//3번 cctv
	{
		for (int i = 0; i < 4; i++)		// 상우, 우하, 하좌, 좌상 
		{
			copy(tmpmap, map);
			spread(i, x, y);
			spread((i + 1) % 4, x, y);
			dfs(count + 1);
			copy(map, tmpmap);
		}
	}
	else if (num == 4)		//4번 cctv
	{
		for (int i = 0; i < 4; i++)		// ㅗ,ㅏ,ㅜ,ㅓ 네번 가능
		{
			copy(tmpmap, map);
			spread(i, x, y);
			spread((i + 1) % 4, x, y);
			spread((i + 2)  % 4, x, y);
			dfs(count + 1);
			copy(map, tmpmap);
		}
	}
	else if (num == 5)		//5번 cctv
	{
		copy(tmpmap, map);			// + 하나만 가능 
		for (int i = 0; i < 4; i++)
		{
			spread(i, x, y);			//각 방향에 대한 spread
		}
		dfs(count + 1);
		copy(map, tmpmap);
	}
}
int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{
				cctv.push_back(map[i][j]);
				loc.push_back(make_pair(i, j));
			}
		}
	}
	
	dfs(0);

	cout << ans << endl;

	return 0;
}