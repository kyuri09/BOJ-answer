#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

long long dp[100001];
int main()
{
	int n, res;
	long long arr[100001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	res = dp[1];

	for (int i = 2; i <= n; i++)
	{
		if (res < dp[i])
			res = dp[i];
	}
	cout << res << "\n";
	return 0;
}