#include <stdio.h>

int c[10], a[10];

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (c[i]) continue;
		c[i] = 1;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = 0;

	}

}
int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	go(0, n, m);

	return 0;
}