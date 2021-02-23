#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int dp[61][61][61];

int go(int i, int j, int k)
{
	if (i < 0) return go(0, j, k);
	if (j < 0) return go(i, 0, k);
	if (k < 0) return go(i, j, 0);

	if (i == 0 && j == 0 && k == 0) return 0;

	int& ans = dp[i][j][k];
	if (ans != -1) return ans;
	ans = 10000000;
	vector<int>p = { 9,3,1 };
	do
	{
		if (ans > go(i - p[0], j - p[1], k - p[2]))
			ans = go(i - p[0], j - p[1], k - p[2]);

	} while (prev_permutation(p.begin(), p.end()));
	ans += 1;
	return ans;
}
int main(void)
{
	int scv[3] = { 0,0,0 };
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(scv[0], scv[1], scv[2]) << endl;
	return 0;
}