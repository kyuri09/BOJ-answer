#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

bool dp[101][1001];
int v[101];

int main(void)
{
	int n, s, m;

	cin >> n >> s >> m;	//���, ���ۺ���,�ִ뺼��

	dp[0][s] = true;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)	//�� ������ŭ
	{
		for (int j = 0; j <= m; j++)	//���� ũ��
		{
			if (dp[i][j] == false) continue;
			if (j- v[i+1] >= 0)
			{
				dp[i+1][j - v[i + 1]] = true;
			}
			if (j + v[i + 1] <= m)
			{
				dp[i+1][j + v[i + 1]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++)
	{
		if (dp[n][i] == true) ans = i;
	}
	cout << ans << endl;
	return 0;
}