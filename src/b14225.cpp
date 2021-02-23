#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool c[20 * 100000];

void go(vector<int> &s, int i, int sum)
{
	if (n == i)
	{
		c[sum] = true;
		return;
	}

	go(s, i + 1, sum + s[i]);
	go(s, i + 1, sum);
}
int main(void)
{
	cin >> n;

	vector<int> s(n);

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	go(s, 0, 0);

	for (int i = 1;; i++)
	{
		if (c[i] == false)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}