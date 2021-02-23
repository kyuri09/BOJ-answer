#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m;
int arr[50][50];
vector<pair<int, int>> ch;
vector<pair<int, int>> ho;

int go(vector<pair<int, int>>& tmp,int h)
{
	int ans = 0;
	
	int temp = 0;

	for (int i = 0; i < h; i++)
	{
		int res = INT_MAX;
		for (int j = 0; j < m; j++)
		{
			temp = abs(ho[i].first - tmp[j].first) + abs(ho[i].second - tmp[j].second);
			if (res >= temp) res = temp;
		}
		ans += res;
	}
	return ans;
}
int main(void)
{
	cin >> n >> m;
	int h = 0, c = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				ho.push_back(make_pair(i, j));
				h++;
			}
			if (arr[i][j] == 2)
			{
				ch.push_back(make_pair(i, j));
				c++;
			}
		}
	}

	vector<int> combi;

	for (int i = 0; i < m; i++)
	{
		combi.push_back(1);
	}
	for (int i = m; i < c; i++)
	{
		combi.push_back(0);
	}

	vector<pair<int, int>> tmp(m);

	sort(combi.begin(), combi.end());
	
	int result = INT_MAX;
	do
	{
		int x = 0;
		for (int i = 0; i < c; i++)
		{
			if (combi[i] == 1)
			{
				tmp[x].first = ch[i].first;
				tmp[x].second = ch[i].second;
				x++;
			}
		}
		int res = go(tmp, h);
		if (result > res) result = res;
	} while (next_permutation(combi.begin(), combi.end()));


	cout << result << endl;

	return 0;
}