#include <stdio.h>

int main(void)
{
	int test;
	int m, n;
	int x, y;
	short int check = 0;

	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);

		x -= 1;
		y -= 1;
		check = 0;
		for (int i = x; i < n * m; i += m)
		{
			if (i % n == y)
			{
				printf("%d\n", i + 1);
				check = 1;
				break;
			}
		}
		if (check == 0) printf("-1\n");
		
	}
}