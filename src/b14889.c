#include <stdio.h>
#include <math.h>

int n;
int team[20][20];
int c1[20],c2[20], a[20];
int res1 = 0,res2=0, ans = 9999;
int stat[2];
int a2[20];

void go3(int index, int n, int m)
{


	if (index == m)
	{
		res2 += team[stat[0] - 1][stat[1] - 1];
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (c2[i]) continue;
		c2[i] = 1;
		stat[index] = a2[i];
		go3(index + 1, n, m);
		c2[i] = 0;
	}

}
void go2(int index, int n, int m)
{
	
	if (index == m)
	{
		res1 += team[stat[0]-1][stat[1]-1];
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (c2[i]) continue;
		c2[i] = 1;
		stat[index] = a[i];
		go2(index + 1, n, m);
		c2[i] = 0;
	}

}
void go(int index, int s, int n, int m)
{
	
	if (index == m)
	{
		res1 = 0;
		res2 = 0;
		int k = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c1[i] == 0)
			{
				a2[k] = i;
				k++;
			}
		}
		go2(0, n / 2, 2);
		go3(0, n / 2, 2);
		if (abs(res1 - res2) < ans)
		{
			ans = abs(res1 - res2);
		}
		return;
	}
	for (int i = s; i <= n; i++)
	{
		if (c1[i]) continue;
		c1[i] = 1;
		a[index] = i;
		go(index + 1,i+1, n, m);
		c1[i] = 0;
	}
}
int main(void)
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &team[i][j]);
		}
	}
	
	go(0,1, n, n / 2);

	printf("%d\n", ans);
	
}