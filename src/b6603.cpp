#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> lotto;

void res(vector<int> &s,int index, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i<lotto.size(); i++)
		{
			cout << lotto[i];
			cout << " ";
		}
		cout << endl;
		return;
	}
	int n = s.size();

	if (n == index) return;	//index ���̶� �迭 ũ��� ������ return
	
	lotto.push_back(s[index]);	//����
	res(s, index + 1, cnt + 1);
	lotto.pop_back();	//���þ���
	res(s, index + 1, cnt);

}
int main(void)
{
	int k;

	while (1)
	{
		cin >> k;
		if (k == 0) break;
		vector<int>s(k);
		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
		}
		res(s, 0, 0);
		cout << endl;
		
	}
	return 0;
}

