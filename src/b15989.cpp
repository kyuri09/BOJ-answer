#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;
int dp[10001];
int main(void)
{
	int t, n;
	int num[3] = { 1,2,3 };
	dp[0] = 1;
	cin >> t;
	
	for (int j=0; j < 3; j++)
	{
		for (int i = 1; i < 10001; i++)
		{
			if (i - num[j] >= 0)
			{
				dp[i] += dp[i - num[j]];
			}
		}
	}

	while (t--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}