/*#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;

int main()
{
	string str;
	string tok;

	cin >> str;
	cin >> tok;


	while (1)
	{
		int idx = str.find(tok, 0);
		if (idx == string::npos)
			break;
		else
			str.erase(idx, tok.length());
	}

	if (str.length() != 0)
		cout << str << "\n";
	else
		cout << "FRULA\n";
} 시간초과 ㅅㅂ */

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

string str, tok, ans;
bool flag;
int main()
{
	cin >> str >> tok;

	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i];

		//입력한 문자열의 끝이 폭발 문자열의 끝과 같은 경우
		if (str[i] == tok[tok.size() - 1] && i >= tok.size() - 1)
		{
			flag = true;
			for (int j = 1; j < tok.size(); j++)
			{
				if (ans[ans.size() - 1 - j] != tok[tok.size() - 1 - j])
					flag = false;
			}
			if (flag)
			{
				for (int k = 0; k < tok.size(); k++)
					ans.pop_back();
			}
		}
	}

	if(!ans.empty())
	{
		cout << ans << "\n";
	}
	else
		cout << "FRULA\n";

	return 0;
}