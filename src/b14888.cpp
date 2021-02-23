#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int sum(vector<int>& num, vector<int>& oper)
{
	int n = num.size();
	int res = num[0];
	for (int i = 1; i < n; i++)
	{
		if (oper[i - 1] == 0)
		{
			res += num[i];
		}
		else if (oper[i - 1] == 1)
		{
			res -= num[i];
		}
		else if (oper[i - 1] == 2)
		{
			res *= num[i];
		}
		else
		{
			res /= num[i];
		}
	}
	return res;
}
int main(void)
{
	int n;
	
	cin >> n;
	
	vector<int> num(n);
	vector<int> oper;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			oper.push_back(i);
		}
	}

	sort(oper.begin(), oper.end());
	vector<int> ans;
	do
	{
		int res = sum(num, oper);
		ans.push_back(res);
		
	} while (next_permutation(oper.begin(), oper.end()));

	sort(ans.begin(), ans.end());

	cout << *(ans.end()-1)  << endl;
	cout << *ans.begin() << endl;

	return 0;

}