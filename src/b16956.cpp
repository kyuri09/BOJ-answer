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

int r, c;
vector<string> map;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string tmp;
		cin >> tmp;
		map.push_back(tmp);
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'W')
			{
				q.push(make_pair(i, j));
			}
		}
	}	
	
	bool flag = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (flag)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || ny<0 || nx>=r || ny>=c)	continue;

				if (map[nx][ny] == 'S')
				{
					cout << "0\n";
					flag = false;
					break;
				}
				if (map[nx][ny] == '.')
				{
					map[nx][ny] = 'D';
				}

			}
		}
	}
	if (flag)
	{
		cout << "1\n";
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}