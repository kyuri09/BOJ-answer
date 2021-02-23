#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	char a[5];
	int cnt = 0, cntd = 0;
	int total = 1;
	scanf("%s", a);

	if (a[0] == 'd') total = 10;
	else if (a[0] == 'c') total = 26;

	for (int i = 1; i < 4; i++)
	{
		if (a[i] == '\0') break;
		if ((a[i] == a[i - 1]))
		{
			if (a[i] == 'd')
			{
				total *= 9;
			}
			else total *= 25;
		}
		else
		{
			if (a[i] == 'd')
			{
				total *= 10;
			}
			else total *= 26;
		}
	}
	printf("%d\n", total);

	return 0;
}