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
			if (i == k) dp[1][k] = cost[1][k];			//ù��° rgb�Ÿ� �� ��������->ó�� ���� r,g,b ���� �� �� ����
			else dp[1][k] = 987654321;
		}
		for (int k = 2; k <= n; k++)				//�ι�°�ٺ��� ����. 
		{
			dp[k][1] = cost[k][1] + min(dp[k - 1][2], dp[k - 1][3]);		
			dp[k][2] = cost[k][2] + min(dp[k - 1][1], dp[k - 1][3]);
			dp[k][3] = cost[k][3] + min(dp[k - 1][1], dp[k - 1][2]);
		}
		for (int k = 1; k < 4; k++)
		{
			if (i != k)		//1�� ���� ���� n�� ���� ���� ���� ���� �����
				res = min(res, dp[n][k]);
		}
	}
	cout << res << "\n";
	return 0;
}