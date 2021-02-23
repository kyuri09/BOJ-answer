#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main()
{
	int n, cnt = 0, a, b;
	vector<pair<int, int>> arr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
		
	}

	sort(arr.begin(), arr.end(), compare);

	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if (x <= arr[i].first)
		{
			x = arr[i].second;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}