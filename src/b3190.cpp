#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int map[101][101];
int d = 1;

void game(int i,vector<pair<int, char>>& xc, vector<pair<int, int>>& snake)
{
	switch (d)
	{
	case 0:
		snake.push_back(make_pair(snake.back().first - 1, snake.back().second));
		if (map[snake.back().first][snake.back().second] == 1)
		{
			map[snake.back().first][snake.back().second] = 2;
		}
		else
		{
			map[snake.front().first][snake.front().second] = 0;
			map[snake.back().first][snake.back().second] = 2;
			snake.erase(snake.begin());
		}
		break;
	case 1:
		snake.push_back(make_pair(snake.back().first, snake.back().second+1));
		if (map[snake.back().first][snake.back().second] == 1)
		{
			map[snake.back().first][snake.back().second] = 2;
		}
		else
		{
			map[snake.front().first][snake.front().second] = 0;
			map[snake.back().first][snake.back().second] = 2;
			snake.erase(snake.begin());
		}
		break;
	case 2:
		snake.push_back(make_pair(snake.back().first +1, snake.back().second));
		if (map[snake.back().first][snake.back().second] == 1)
		{
			map[snake.back().first][snake.back().second] = 2;
		}
		else
		{
			map[snake.front().first][snake.front().second] = 0;
			map[snake.back().first][snake.back().second] = 2;
			snake.erase(snake.begin());
		}
		break;
	case 3:
		snake.push_back(make_pair(snake.back().first, snake.back().second-1));
		if (map[snake.back().first][snake.back().second] == 1)
		{
			map[snake.back().first][snake.back().second] = 2;
		}
		else
		{
			map[snake.front().first][snake.front().second] = 0;
			map[snake.back().first][snake.back().second] = 2;
			snake.erase(snake.begin());
		}
		break;
	}
	for (int x=0;x<xc.size();x++)
	{
		if (xc[x].first == i)
		{
			if (xc[x].second == 'D')
			{
				if (d != 3) d += 1;
				else d = 0;
			}
			else if (xc[x].second == 'L')
			{
				if (d != 0) d -= 1;
				else d = 3;
			}
		}
	}
}
int end_game(vector<pair<int, char>>& xc, vector<pair<int, int>>& snake)
{
	int time = 0;
	int flag = 0;
	for (int i = 1;; ++i)	//�ð� ���� ����
	{
		if (snake.back().first == 0 || snake.back().second == 0)	//�Ӹ� ���� ��°��
		{
			time = i-1;
			flag = 1;
			//break;
		}
		else if (snake.back().first == n+1  || snake.back().second == n+1 )	//�Ӹ� ���� ��°��
		{
			time = i-1;
			flag = 1;
			//break;
		}
		for (int j = 0; j < snake.size()-1; j++)	//����� ���� ->����� �ȴ���� Ȯ��
		{
			if (d == 0)
			{
				if (snake.back().first-1 == snake[j].first && snake.back().second == snake[j].second)		//����̶� �Ӹ��� ��°��
				{
					time = i;
					flag = 1;
					break;
				}
			}
			if (d == 1)
			{
				if (snake.back().first  == snake[j].first && snake.back().second+1 == snake[j].second)		//����̶� �Ӹ��� ��°��
				{
					time = i;
					flag = 1;
					break;
				}
			}
			if (d == 2)
			{
				if (snake.back().first + 1 == snake[j].first && snake.back().second == snake[j].second)		//����̶� �Ӹ��� ��°��
				{
					time = i;
					flag = 1;
					break;
				}
			}
			if (d == 3)
			{
				if (snake.back().first  == snake[j].first && snake.back().second-1 == snake[j].second)		//����̶� �Ӹ��� ��°��
				{
					time = i;
					flag = 1;
					break;
				}
			}
			
			
		}
		game(i, xc, snake);
		if (flag == 1) break;
	}
	return time;
}

int main(void)
{

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;;				
		map[x][y] = 1;		//��� ��ġ
	}
	
	int l, t;
	char rot;

	cin >> l;

	vector<pair<int, char>> xc;		//�ð��ʶ� ���� 

	for (int i = 0; i < l; i++)
	{
		int a; char b;
		cin >> a >> b;			
		xc.push_back(make_pair(a, b));			//�ʶ� ���� �Է�
	}
	
	vector<pair<int, int>>snake;			//�� ���� 

	snake.push_back(make_pair(1, 1));		//�� ó�� ��ġ
	map[1][1] = 2;
	cout << end_game(xc, snake) << endl;

	return 0;
}