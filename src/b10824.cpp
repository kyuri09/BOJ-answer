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
	int a, b, c, d;
	string s1,s2;
	string aa, bb, cc, dd;
	cin >> a >> b >> c >> d;

	aa = to_string(a);
	bb = to_string(b);
	cc = to_string(c);
	dd = to_string(d);
	
	s1 = aa + bb;
	s2 = cc + dd;

	cout << stoll(s1) + stoll(s2) << "\n";

	return 0;
}