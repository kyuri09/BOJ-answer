#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>

using namespace std;
const long long limit = 1000000000LL;
long long s, t;
int main(void)
{
	cin >> s >> t;

	set<long long> check;
	queue<pair<long long, string>> q;
	
	q.push(make_pair(s, ""));
	
	while (!q.empty())
	{
		long long x;
		string str;
		tie(x, str) = q.front();
		q.pop();
		if (x == t)
		{
			if (str.length() == 0)
			{
				str = "0";
			}
			cout << str << endl;
			return 0;
		}
		if (0 <= x * x && x * x <= limit && check.count(x * x) == 0)
		{
			check.insert(x * x);
			q.push(make_pair(x * x, str + '*'));
		}
		if (0 <= x + x && x + x <= limit && check.count(x + x) == 0)
		{
			check.insert(x + x);
			q.push(make_pair(x + x, str + '+'));
		}
		if (0 <= x - x && x - x <= limit && check.count(x - x) == 0)
		{
			check.insert(x - x);
			q.push(make_pair(x - x, str + '-'));
		}
		if (x != 0 && x / x < limit && check.count(x / x) == 0)
		{
			check.insert(x / x);
			q.push(make_pair(x / x, str + '/'));
		}
	}
	
	cout << -1 << endl;
}
