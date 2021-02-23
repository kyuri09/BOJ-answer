#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	int n, k;
	int coin[10];
	int cnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	for (int i = n-1; i >= 0; i--)
	{
		if (k >= coin[i])
		{
			cnt += (k / coin[i]);
			k = k % coin[i];
		}
		else continue;
	}
	cout << cnt;
}