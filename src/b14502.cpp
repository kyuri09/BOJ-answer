#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int lab[9][9];
int tmplab[9][9];
int n, m;
int zeroc = 0;
int maxi = 0;

void copy(int(*a)[9], int(*b)[9])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void virus()
{
	int flag = 0;
	zeroc = 0;
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmplab[i][j] == 2)
				{
					if (i != 0)	// 위에 볼수있음
					{
						if (tmplab[i - 1][j] == 0)
						{
							tmplab[i - 1][j] = 2;
							flag = 1;
						}
					}
					if (j != 0)	//왼쪽 볼수있음
					{
						if (tmplab[i][j - 1] == 0)
						{
							tmplab[i][j - 1] = 2;
							flag = 1;
						}
					}
					if (i != n - 1)	//아래 볼수있음
					{
						if (tmplab[i + 1][j] == 0)
						{
							tmplab[i + 1][j] = 2;
							flag = 1;
						}
					}
					if (j != m - 1)	//오른쪽 볼수있음
					{
						if (tmplab[i][j + 1] == 0)
						{
							tmplab[i][j + 1] = 2;
							flag = 1;
						}
					}
				}
			}
		}
		if (flag == 0) 
			break;
		if (flag == 1) flag = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmplab[i][j] == 0)
			{
				zeroc++;
			}
		}
	}
	
}
void wall(int count)
{
	if (count == 3)
	{
		copy(tmplab, lab);
		virus();
		if (maxi < zeroc)
		{
			maxi = zeroc;
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0)
			{	
				
				//copy(tmplab, lab);
				lab[i][j] = 1;		//벽세운뒤
				wall(count + 1);		//재귀 돌리고
				lab[i][j] = 0;		//다시 벽 복구
			}
		}
	}
}
int main(void)
{
	int count = 0;
	//int w = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &lab[i][j]);
		}
	}

	wall(0);
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0)
			{
				//copy(tmplab, lab);
				lab[i][j] = 1;		//벽세운뒤
				wall(0);				//재귀 돌리고 끝나면
				lab[i][j] = 0;		//다시 복구
				
			}
		}
	}
	*/
	printf("%d\n", maxi);

}