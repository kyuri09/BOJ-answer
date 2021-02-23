#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tetro[500][500];
bool c[500][500];
int n, m;
int result = 0;
int dx[] = { 0,0,-1,1 };		//���� ->��κ� �¿�x
int dy[] = { 1,-1,0,0 };		//���� ->���κ� ����x

void go(int x, int y, int sum, int cnt)
{
	if (cnt == 4)
	{
		if (result < sum) result = sum;
		return;
	}
	if (x < 0 || y < 0 || x >= n || y >= m) return;
	if (c[x][y]) return;
	c[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		go(x + dx[i], y + dy[i], sum + tetro[x][y], cnt + 1);
	}
	c[x][y] = false;
}
int main(void)
{
	int tmp, tmp2;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tetro[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			go(i, j, 0, 0);
			if (j + 2 < m)
			{
				tmp = tetro[i][j] + tetro[i][j + 1] + tetro[i][j + 2];
				if (i - 1 >= 0)						//�Ǹ��
				{
					tmp2 = tmp + tetro[i - 1][j + 1];
					if (result < tmp2) result = tmp2;
				}
				if (i + 1 < n)					//�̸��
				{
					tmp2 = tmp + tetro[i + 1][j + 1];
					if (result < tmp2) result = tmp2;
				}
			}
			if (i + 2 < n)
			{
				tmp = tetro[i][j] + tetro[i + 1][j] + tetro[i + 2][j];

				if (j - 1 >= 0)				//�ø��
				{
					tmp2 = tmp + tetro[i + 1][j - 1];
					if (result < tmp2) result = tmp2;
				}
				if (j + 1 < m)				//�����
				{
					tmp2 = tmp + tetro[i + 1][j + 1];
					if (result < tmp2) result = tmp2;
				}
			}		
		}
	}
	cout << result << endl;

	return 0;
}