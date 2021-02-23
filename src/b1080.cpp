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
	int n, m;
	vector<string> a, b;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j])
			{
				cnt++;
				for (int k = i; k < i + 3; k++)
				{
					for (int l = j; l < j + 3; l++)
					{
						if (a[k][l] == '0') a[k][l] = '1';
						else a[k][l] = '0';
					}
				}
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (flag)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != b[i][j])
				{
					flag = false;
					break;
				}
			}
		}
	}

	if (flag) cout << cnt << "\n";
	else cout << "-1" << "\n";

	return 0;
}