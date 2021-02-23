#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a;
	stack<int> s;
	vector<char> c;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<int>::iterator it;
	it = a.begin();
	for (int i = 1; i <= n; i++)
	{
		s.push(i);	// 스택에 입력
		c.push_back('+');		
		while (!s.empty())
		{
			if (s.top() != *it)		//스택에 있는 값이랑 같지 않으면 넘김
			{
				break;
			}
			else
			{				// 같으면 pop하고 -넣어줌
				s.pop();
				c.push_back('-');
				it++;
			}
		}
	}
	if (s.empty())
	{
		for (int i = 0; i < c.size(); i++)
		{
			cout << c[i] << "\n";
		}
	}
	else cout << "NO" << "\n";
}