#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

bool prime[10001];
bool check[10001];
int dist[10001];

void make_prime()
{

	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		prime[i] = !prime[i];
	}
}
int change(int num, int index, int digit)
{
	if (index == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[index] = digit + '0';
	
	return stoi(s);
}
int main(void)
{
	make_prime();
	int t;
	cin >> t;

	while (t--)
	{
		int x, y, digit;
		cin >> x >> y;
		for (int i = 0; i < 10001; i++)
		{
			dist[i] = 0;
			check[i] = false;
		}
		queue<int> q;
		q.push(x);
		dist[x] = 0;
		check[x] = true;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int next = change(now, i, j);
					if (next != -1)
					{
						if (check[next] == false && prime[next])
						{
							dist[next] = dist[now] + 1;
							q.push(next);
							check[next] = true;
						}
					}
				}
			}
		}
		if (check[y])
			cout << dist[y] << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
