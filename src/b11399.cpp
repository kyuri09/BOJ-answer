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
	int n;
	vector<int> arr;
	int sum = 0;
	int tmp[1001];
	cin >> n;

	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			tmp[i] += arr[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum += tmp[i];
	}

	cout << sum << "\n";
	return 0;
}