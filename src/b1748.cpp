#include <stdio.h>

int main(void)
{
	int n;
	long long sum = 0;
	int len = 1;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i *= 10)
	{
		int result = i * 10 - 1;
		if (result > n)
		{
			result = n;
		}
		sum += (long long)(result-i+1) * len;
		len++;
	}

	printf("%lld\n", sum);
}