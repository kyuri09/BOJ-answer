#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int v[101];
int w[101];
int d[100001];

int main(void)
{
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <=n; i++)
	{
		for (int j = k; j >= 1; j--)
		{
			if (j - w[i] >= 0)
			{
				d[j] = max(d[j], d[j - w[i]] + v[i]);
			}
		}
	}
	cout << d[k] << endl;
	return 0;
}