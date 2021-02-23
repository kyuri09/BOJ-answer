#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string board[20];
int ans = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int go(int step, int x1, int y1, int x2, int y2)
{
	if (step == 11) return -1;
	bool coin1 = false, coin2 = false;

	if (x1<0 || y1<0 || x1>n - 1 || y1>m - 1) coin1 = true;			//������
	if (x2<0 || y2<0 || x2>n - 1 || y2>m - 1) coin2 = true;			//������
	if (coin1 && coin2) return -1;			//�ΰ� �� ������ ���
	if (coin1 || coin2) return step;		//���� �ϳ��� �������� ��ư ���� Ƚ�� ����
	int res = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];

		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m)		
		{				
			if (board[nx1][ny1] == '#')			//�̵��Ϸ��� ĭ�� ���̸� �̵�x
			{
				nx1 = x1;
				ny1 = y1;
			}
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m)	    
		{
			if (board[nx2][ny2] == '#')		//�̵��Ϸ��� ĭ�� ���̸� �̵�x
			{
				nx2 = x2;
				ny2 = y2;
			}
		}
		int tmp = go(step + 1, nx1, ny1, nx2, ny2);
		if (tmp == -1) continue;
		if (res == -1 || res > tmp)
			res = tmp;
	}
	return res;
}
int main(void)
{
	cin >> n >> m;
	int x1, x2, y1, y2;
	x1 = x2 = y1 = y2 = -1;			//�� -1??
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'o')
			{
				if (x1 == -1)		//����1
				{
					x1 = i;
					y1 = j;
				}
				else				//����2
				{
					x2 = i;
					y2 = j;
				}
				board[i][j] = '.';		//������ �ִ�ĭ �׻� ��ĭ
			}
		}
	}
	
	ans = go(0, x1, y1, x2, y2);

	cout << ans << endl;

}