#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;
int t[1500001];
int p[1500001];
int dp[1500001] = { 0 };

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		//scanf("%d %d", &t[i], &p[i]);
		cin >> t[i] >> p[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		if (i + t[i] <= n)
		{
			dp[i + t[i]] = max(dp[i] + p[i], dp[i + t[i]]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[n] << endl;
	return 0;
}