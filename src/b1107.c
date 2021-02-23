#include <stdio.h>

int rem[10];
int check(int x)
{
	int len = 0;
	if (x == 0)
	{
		if (rem[0] == 0) return 0;
		else return 1;
	}

	while (x)
	{
		len++;
		if (rem[x % 10] == 0) return 0;
		x = x / 10;
	}
	
	return len;
}
int main(void)
{
	int n, m;
	int k;
	
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < 10; i++)
	{
		rem[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		rem[k] = 0;
	}
	
	int result;
	
	result = n - 100;
	if (result < 0)
	{
		result = result * -1;
	}

	int l;
	int ud;

	for (int i = 0; i < 1000000; i++)
	{
		l = check(i);
		if (l > 0)
		{
			ud = i - n;
			if (ud < 0) ud = ud * -1;
			if (result > ud + l) result = ud + l;
		}
	}

	printf("%d\n", result);

	return 0;
}