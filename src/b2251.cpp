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

int a, b, c;
bool visited[201][201][201];
vector<int> res;
int main()
{
	cin >> a >> b >> c;
	queue<tuple<int, int, int>> q;

	q.push(make_tuple(0, 0, c));

	while (!q.empty())
	{
		int aa, bb, cc;
		tie(aa, bb, cc) = q.front();
		q.pop();

		if (!visited[aa][bb][cc])
		{
			if (aa == 0)
				res.push_back(cc);
			//a->b
			if (aa + bb <= b)				//a�� b�뿡 ���� �� �ȳ�ġ�� a�� b�뿡 �� ����  
				q.push(make_tuple(0, aa + bb, cc));
			else
				q.push(make_tuple(aa + bb - b, b, cc));				//��ġ�� b�뿡 �Ѱ���� �ְ� ������ a�� ����
			
			//a->c
			if (aa + cc <= c)
				q.push(make_tuple(0, bb, aa + cc));	//a�� c�뿡 ���� �� �ȳ�ġ�� a�� c�뿡 �� ����
			else
				q.push(make_tuple(aa + cc - c, bb, c));		//��ġ�� c�뿡 �Ѱ���� �ְ� ������ a�� ����
			
			//b->a
			if (bb + aa <= a)
				q.push(make_tuple(bb + aa, 0, cc));		//b�� a�뿡 ���� �� �ȳ�ġ�� b�� a�뿡 �� ����
			else
				q.push(make_tuple(a, bb + aa - a, cc));			//��ġ�� a�뿡 �Ѱ���� �ְ� ������ b�� ���� 
			
			//b->c
			if (bb + cc <= c)
				q.push(make_tuple(aa, 0, bb + cc));			//b�� c�뿡 ���� �� �ȳ�ġ�� b�� c�뿡 �� ����
			else
				q.push(make_tuple(aa, bb + cc - c, c));			//��ġ�� c�뿡 �Ѱ���� �ְ� ������ b�� ���� 

			//c->a
			if (cc + aa <= a)
				q.push(make_tuple(cc + aa, bb, 0));		//c�� a�뿡 ���� �� �ȳ�ġ�� c�� a�뿡 �� ����
			else
				q.push(make_tuple(a, bb, cc + aa - a));		//��ġ�� a�뿡 �Ѱ���� �ְ� ������ c�� ����

			//c->b
			if (cc + bb <= b)
				q.push(make_tuple(aa, cc + bb, 0));			//c�� b�뿡 ���� �� �ȳ�ġ�� c�� b�뿡 �� ����
			else
				q.push(make_tuple(aa, b, cc + bb - b));		//��ġ�� b�뿡 �Ѱ���� �ְ� ������ c�� ����
		}
		visited[aa][bb][cc] = true;
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] <<" ";
	}
	return 0;
}