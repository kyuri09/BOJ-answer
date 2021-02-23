#include <iostream>

using namespace std;

int room[50][50];
int tmproom[50][50];
int r, c, t;

void spread()
{
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			count = 0;
			if (room[i][j] > 0)
			{
				if (i != 0)	//위에 갈수있음
				{
					if (tmproom[i - 1][j] != -1)
					{
						tmproom[i - 1][j] += room[i][j] / 5;
						count++;
					}
				}
				if (j != 0)	//왼쪽 갈수 있음
				{
					if (tmproom[i][j - 1] != -1)
					{
						tmproom[i][j - 1] += room[i][j] / 5;
						count++;
					}
				}
				if (i != r - 1)	//아래 갈수있음
				{
					if (tmproom[i + 1][j] != -1)
					{
						tmproom[i + 1][j] += room[i][j] / 5;
						count++;
					}
				}
				if (j != c - 1)	//오른쪽 갈수있음
				{
					if (tmproom[i][j + 1] != -1)
					{
						tmproom[i][j + 1] += room[i][j] / 5;
						count++;
					}
				}
				tmproom[i][j] = tmproom[i][j] - (room[i][j] / 5) * count;
			}
		}
	}
}
void aircleaner()
{
	int cleaner;
	int flag = 0;

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (room[j][i] == -1)
			{
				cleaner = j;
				break;
			}
		}
	}

	for (int i = cleaner - 1; i > 0; i--)
	{
		tmproom[i][0] = tmproom[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++)
	{
		tmproom[0][i] = tmproom[0][i + 1];
	}
	for (int i = 0; i < cleaner; i++)
	{
		tmproom[i][c - 1] = tmproom[i + 1][c - 1];
	}
	for (int i = c - 1; i > 0; i--)
	{
		tmproom[cleaner][i] = tmproom[cleaner][i-1];
	}

	tmproom[cleaner][1] = 0;


	cleaner += 1;

	for (int i = cleaner + 1; i < r - 1; i++)
	{
		tmproom[i][0] = tmproom[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++)
	{
		tmproom[r - 1][i] = tmproom[r - 1][i + 1];
	}
	for (int i = r - 1; i > cleaner; i--)
	{
		tmproom[i][c - 1] = tmproom[i - 1][c - 1];
	}
	for (int i = c - 1; i > 0; i--)
	{
		tmproom[cleaner][i] = tmproom[cleaner][i-1];
	}
	tmproom[cleaner][1] = 0;



	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			room[i][j] = tmproom[i][j];
		}
	}
}
int main(void)
{
	int dust = 0;

	scanf("%d %d %d", &r, &c, &t);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tmproom[i][j] = room[i][j];
		}
	}

	for (int i = 0; i < t; i++)
	{
		spread();
		aircleaner();
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (room[i][j] > 0)
			{
				dust += room[i][j];
			}
		}
	}

	printf("%d\n", dust);
}