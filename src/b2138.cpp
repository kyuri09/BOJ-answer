#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;

int n, ans = 9999;
string a, b, tmp;
bool flag = false;
void compare(string& s, int idx, int cnt)
{
	if (idx == n - 1)
	{
		if (s[idx - 1] == b[idx - 1] && s[idx] == b[idx])
		{
			flag = true;
			ans = min(ans, cnt);
		}
		for (int i = idx - 1; i <= idx; i++)
		{
			if (s[i] == '0') s[i] = '1';
			else s[i] = '0';
		}
		if (s[idx - 1] == b[idx - 1] && s[idx] == b[idx])
		{
			flag = true;
			ans = min(ans, cnt + 1);
		}
		return;
	}
	if (s[idx - 1] == b[idx-1])
		compare(s, idx + 1, cnt);
	for (int i = idx - 1; i <= idx + 1; i++)
	{
		if (s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
	if (s[idx - 1] == b[idx - 1])
		compare(s, idx + 1, cnt + 1);
}
int main()
{
	cin >> n >> a >> b;

	tmp = a;

	for (int i = 0; i <= 1; i++)
	{
		if (tmp[i] == '0') tmp[i] = '1';
		else tmp[i] = '0';
	}
	compare(tmp, 1, 0);
	compare(tmp, 1, 1);

	if (flag) cout << ans << "\n";
	else cout << "-1\n";


	return 0;
}