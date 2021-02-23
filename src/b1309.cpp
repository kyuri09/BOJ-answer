#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int dp[100001];
int main()
{
	int n;
	cin >> n;

	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = ((dp[i - 1] * 2) + dp[i - 2]) % 9901;
	}
	cout << dp[n] << "\n";

	return 0;
}