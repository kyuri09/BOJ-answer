#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int dp[501][501];
int file[501];

int go(int i, int j)
{
	if (i == j) return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int sum = 0;
	int &ans = dp[i][j];
	for (int k = i; k <= j; k++)
	{
		sum += file[k];
	}
	int tmp = 0;
	for (int k = i; k <= j; k++)
	{
		tmp = go(i, k) + go(k + 1, j) + sum;
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}
int main(void)
{
	int t, k;

	cin >> t;
	
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> file[i];
		}
		cout << go(0, k-1) << endl;
	}
	return 0;
}