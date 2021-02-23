#include <stdio.h>

int room[50][50];
int r, c, d;
int n, m;
int count = 1;
void clean()
{
	int dir = 0;
	int flag = 0;
	int flag2 = 0;

	
	room[r][c] = -1;

	while (1)
	{
		switch (d)
		{
		case 0:
			if (room[r][c - 1] == 0)	//왼쪽방향 청소공간 있음
			{
				room[r][c - 1] = -1;		//청소
				c = c - 1;					//왼쪽으로 전진
				d = 3;				//바라보는 방향 바꿔줌
				dir = 0;			//회전 횟수 초기화
				count++;			//청소방 ++
			}
			else   
			{				//왼쪽방향 청소공간 없음
				d = 3;		//바라보는 방향만 바꿔줌
				dir++;		//회전 횟수 증가
				flag = 1;		//왼쪽방향 청소공간 없다는 flag
			}
			break;
		case 1:
			if (room[r -1][c] == 0)
			{
				room[r - 1][c] = -1;
				r = r - 1;
				d = 0;
				dir = 0;
				count++;
			}
			else
			{
				d = 0;
				dir++;
				flag = 1;
			}
			break;
		case 2:
			if (room[r][c + 1] == 0)
			{
				room[r][c + 1] = -1;
				c = c + 1;
				d = 1;
				dir = 0;
				count++;
			}
			else
			{
				d = 1;
				dir++;
				flag = 1;
			}
			break;
		case 3:
			if (room[r + 1][c] == 0)
			{
				room[r + 1][c] = -1;
				r = r + 1;
				dir = 0;
				d = 2;
				count++;
			}
			else
			{
				d = 2;
				dir++;
				flag = 1;
			}
			break;
		}
		if (dir == 4&&flag==1)		//다 돌았는데 없는 경우
		{	
			switch (d)			//후진
			{
			case 0:
				r = r + 1;
				dir = 0;
				if (room[r][c] == 1 ) flag2 = 1;
				break;
			case 1:
				c = c - 1;
				dir = 0;
				if (room[r][c] == 1 ) flag2 = 1;
				break;
			case 2:
				r = r - 1;
				dir = 0;
				if (room[r][c] == 1) flag2 = 1;
				break;
			case 3:
				c = c + 1;
				dir = 0;
				if (room[r][c] == 1) flag2 = 1;
				break;
			}
		}
		if (flag2 == 1) break;
	}
}
int main(void)
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}

	clean();

	printf("%d\n", count);
}