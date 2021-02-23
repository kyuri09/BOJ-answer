#include <stdio.h>

int main()
{
	int a, b, c;
	int x, y;
	int total=0;

	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

	//total = a * x + b * y;
	if (c * 2 < a + b)
	{
		while (x >= 1 && y >= 1)
		{
			total += c * 2;
			x--;
			y--;

		}
		if (x == 0)
		{
			if (b < c * 2)
			{
				total += (b * y);
			}
			else total += (c * 2 * y);
		}
		else if (y == 0)
		{
			if (a < c * 2)
			{
				total += (a * x);
			}
			else total += (c * 2 * x);
		}
	}
	else total += (x * a + y * b);
	printf("%d\n", total);
}