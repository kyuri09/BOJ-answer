#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	bool flag=false;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string a;
		string tmp;
		getline(cin, a);
		for (int i = 0; i < a.size(); i++)
		{	
			if (a[i] == '(')
				tmp.push_back(a[i]);
			else if (a[i] == ')')
			{
				if (tmp.empty()||tmp.back() == '(')
				{
					flag = true;
					if (!tmp.empty())
						tmp.pop_back();
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == false )
		{
			cout << "NO" << endl;
		}
		else 
		{
			if (tmp.size() != 0)
			{
				cout << "NO" << endl;
			}
			else
				cout << "YES" << endl;
		}
		tmp.clear();
	}
}