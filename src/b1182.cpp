#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int res = 0;

void go(vector<int>& a, int i, int sum)
{
	if (i == n)
	{
		if (s == sum)
		{
			res++;
		}
		return;
	}

	go(a, i + 1, sum + a[i]);
	go(a, i + 1, sum);

}
int main(void)
{
	cin >> n >> s;
	
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	go(a, 0, 0);
	if (s == 0) res -= 1;		//아무것도 선택하지 않는 경우
	cout << res << endl;

	return 0;
}