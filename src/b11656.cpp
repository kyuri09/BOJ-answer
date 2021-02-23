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
	string s;
	vector<string> ss;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		ss.push_back(s.substr(i));
	}
	sort(ss.begin(), ss.end());
	for (int i = 0; i < s.size(); i++)
	{
		cout << ss[i] << "\n";
	}
}