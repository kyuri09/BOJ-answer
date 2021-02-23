#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
bool check[1501][1501];
int sum;

int main(void)
{
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));

	check[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		if (x == y && y == z)
		{
			cout << 1 << endl;
			return 0;
		}
		q.pop();
		int nx[] = { x,y,z }; int ny[] = { y,z,x };
		for (int i = 0; i < 3; i++)
		{
			int na = nx[i];
			int nb = ny[i];
			if (na < nb)
			{
				nb = nb - na;
				na = na + na;
			}
			else if (na > nb)
			{
				na = na - nb;
				nb = nb + nb;		
			}
			else continue;
			int nc = sum - na - nb;
			x = min(min(na, nb), nc);
			y = max(max(na, nb), nc);
			if (!check[x][y])
			{
				q.push(make_pair(x, y));
				check[x][y] = true;
			}
		}
	}
	cout << 0 << endl;
	
	return 0;
}