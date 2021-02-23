#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int dp[1001][4];
int main()
{
	int cost[1001][4];
	int n, res = 987654321;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			cin >> cost[i][j];
		}
	}

	for (int i = 1; i < 4; i++)
	{
		for (int k = 1; k < 4; k++)
		{
			if (i == k) dp[1][k] = cost[1][k];			//첫번째 rgb거리 집 기준으로->처음 라인 r,g,b 각각 일 때 기준
			else dp[1][k] = 987654321;
		}
		for (int k = 2; k <= n; k++)				//두번째줄부터 구함. 
		{
			dp[k][1] = cost[k][1] + min(dp[k - 1][2], dp[k - 1][3]);		
			dp[k][2] = cost[k][2] + min(dp[k - 1][1], dp[k - 1][3]);
			dp[k][3] = cost[k][3] + min(dp[k - 1][1], dp[k - 1][2]);
		}
		for (int k = 1; k < 4; k++)
		{
			if (i != k)		//1번 집의 색과 n번 집의 색이 같지 않은 경우임
				res = min(res, dp[n][k]);
		}
	}
	cout << res << "\n";
	return 0;
}