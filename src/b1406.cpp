#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	string a;
	int n;
	
	cin >> a;
	cin >> n;
	stack<char> s1, s2;

	for (int i = 0; i < a.size(); i++)
	{
		s1.push(a[i]);
	}
	while (n--)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'L')
		{
			if (!(s1.empty()))		//Ŀ���� �� ���ʿ� ���� ����
			{
				s2.push(s1.top());		//Ŀ�� ��ġ �������� �ű� ->�ٸ� ���ÿ� Ŀ�� �����ʿ� �ִ°� �ű�
				s1.pop();
			}
		}
		else if (cmd == 'D')
		{
			if (!(s2.empty()))	//Ŀ���� �� �����ʿ� ���� ����
			{
				s1.push(s2.top());		//Ŀ�� ��ġ ���������� �ű�->�ٸ� ���ÿ� Ŀ�� ���ʿ� �ִ� �� �ű�
				s2.pop();
			}
		}
		else if (cmd == 'B')
		{
			if (!(s1.empty()))		//Ŀ���� �� ���ʿ� ���� ����
			{
				s1.pop();
			}
		}
		else if (cmd == 'P')
		{
			char x;
			cin >> x;
			s1.push(x);
		}
	}
	while(!(s1.empty()))
	{
		char tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	}
	
	while (!(s2.empty()))
	{
		cout << s2.top();
		s2.pop();
	}
	cout << "\n";

	return 0;
}