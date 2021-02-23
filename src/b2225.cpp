#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
int dp[201][201];

int main()
{
	int div = 1000000000;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % div;
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}
