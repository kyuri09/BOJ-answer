#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;

	string a;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		getline(cin, a);
		string tmp;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == ' ')
			{
				reverse(tmp.begin(), tmp.end());
				cout << tmp << " ";
				tmp.clear();
			}
			else
				tmp += a[i];
		}
		reverse(tmp.begin(), tmp.end());
		cout << tmp << endl;
	}
}