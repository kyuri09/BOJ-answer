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
			if (aa + bb <= b)				//a를 b통에 넣을 때 안넘치면 a를 b통에 다 넣음  
				q.push(make_tuple(0, aa + bb, cc));
			else
				q.push(make_tuple(aa + bb - b, b, cc));				//넘치면 b통에 한계까지 넣고 남은거 a에 있음
			
			//a->c
			if (aa + cc <= c)
				q.push(make_tuple(0, bb, aa + cc));	//a를 c통에 넣을 때 안넘치면 a를 c통에 다 넣음
			else
				q.push(make_tuple(aa + cc - c, bb, c));		//넘치면 c통에 한계까지 넣고 남은거 a에 있음
			
			//b->a
			if (bb + aa <= a)
				q.push(make_tuple(bb + aa, 0, cc));		//b를 a통에 넣을 때 안넘치면 b를 a통에 다 넣음
			else
				q.push(make_tuple(a, bb + aa - a, cc));			//넘치면 a통에 한계까지 넣고 남은거 b에 있음 
			
			//b->c
			if (bb + cc <= c)
				q.push(make_tuple(aa, 0, bb + cc));			//b를 c통에 넣을 때 안넘치면 b를 c통에 다 넣음
			else
				q.push(make_tuple(aa, bb + cc - c, c));			//넘치면 c통에 한계까지 넣고 남은거 b에 있음 

			//c->a
			if (cc + aa <= a)
				q.push(make_tuple(cc + aa, bb, 0));		//c를 a통에 넣을 때 안넘치면 c를 a통에 다 넣음
			else
				q.push(make_tuple(a, bb, cc + aa - a));		//넘치면 a통에 한계까지 넣고 남은거 c에 있음

			//c->b
			if (cc + bb <= b)
				q.push(make_tuple(aa, cc + bb, 0));			//c를 b통에 넣을 때 안넘치면 c를 b통에 다 넣음
			else
				q.push(make_tuple(aa, b, cc + bb - b));		//넘치면 b통에 한계까지 넣고 남은거 c에 있음
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