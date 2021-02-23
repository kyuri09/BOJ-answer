#include <iostream>

using namespace std;

int n, l;
int map[100][100];

int slope(int(*map)[100])
{
	int count = 0;
	int lcount = 0;
	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		lcount = 1;
		flag = 0;
		for (int j = 0; j+1 < n; j++)
		{
			if (map[i][j] == map[i][j+1]) lcount++;		//���ӵ� ����
			else if (map[i][j] - map[i][j + 1] == 1)			//��� ������ ���
			{
				if (lcount < 0)			//
				{
					flag = 1;
				}
				else
				{
					lcount = -(l - 1);
				}
			}
			else if (map[i][j] - map[i][j+1] == -1)		//��� ������ ���
			{
				if (lcount >= l)
				{
					lcount = 1;		//���� �� �ִ� ���ӵ� ��� ������ �ٽ� 1	
				}
				else flag = 1;
			}
			else flag = 1;
		}
		if (lcount >= 0 && flag == 0) count++;
	}

	for (int i = 0; i < n; i++)
	{
		lcount = 1;
		flag = 0;
		for (int j = 0; j+1 < n; j++)
		{
			if (map[j+1][i] == map[j][i]) lcount++;		//���ӵ� ����
			else if (map[j][i] - map[j + 1][i] == 1)			//��� ������ ���
			{
				if (lcount < 0)
				{
					flag = 1;
				}
				else
				{
					lcount = -(l - 1);
				}
			}
			else if (map[j][i] - map[j + 1][i] == -1)		//��� ������ ���
			{
				if (lcount >= l)
				{
					lcount = 1;		//���� �� �ִ� ���ӵ� ��� ������ �ٽ� 1	
				}
				else flag = 1;
			}
			else flag = 1;
		}
		if (lcount >= 0 && flag == 0) count++;
	}

	return count;
}
int main(void)
{
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", slope(map));
}