#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>

using namespace std;

int n, m;
int a[1001][1001];
int d[1001][1001];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}
	cout << d[n][m] << endl;
}