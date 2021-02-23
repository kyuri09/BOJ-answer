#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int n;
int a[1001];
int d[1001];

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	d[0] = d[1] = 0;
	for (int i = 1; i < n; i++)
	{
		if (d[i] == -1) continue;
		for (int j = 1; j <= a[i]; j++)
		{
			if (i + j > n) break;
			if (d[i + j] == -1 || d[i + j] > d[i] + 1)
			{
				d[i + j] = d[i] + 1;
			}
		}
	}
	cout << d[n] << endl;
}