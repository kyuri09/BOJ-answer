#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

long long mod=1000000007;
int dp[5001];

int go(int n)
{

}
int main(void)
{
	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		if (n % 2 == 0)
		{
			cout << go(n) << endl;
		}
		else cout << 0 << endl;

	}

}