#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t;
char how[10001];
int from[10001];
int dist[10001];
bool visited[10001];
char cmd[] = { 'D','S','L','R' };

void print(int num1, int num2)
{
	if (num1 == num2) return;
	print(num1, from[num2]);
	cout << how[num2];
}
int main(void)
{
	cin >> t;

	while (t--)
	{
		int n1, n2;
		cin >> n1 >> n2;
		
		for (int i = 0; i < 10001; i++)
		{
			visited[i] = false;
		}
		queue<int> q;
		q.push(n1);
		dist[n1] = 0;
		visited[n1] = true;

		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (cmd[i] == 'D')
				{
					int next = (now * 2) % 10000;
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						how[next] = cmd[i];
						from[next] = now;
						dist[next] = dist[now] + 1;
					}
				}
				else if (cmd[i] == 'S')
				{
					int next = now - 1;
					if (visited[next] == false)
					{				
						if (now == 0) next = 9999;
						q.push(next);
						visited[next] = true;
						how[next] = cmd[i];
						from[next] = now;
						dist[next] = dist[now] + 1;
					}
				}
				else if (cmd[i] == 'L')
				{
					int next = ((now % 1000) * 10) + (now / 1000);
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						how[next] = cmd[i];
						from[next] = now;
						dist[next] = dist[now] + 1;
					}
				}
				else if (cmd[i] == 'R')
				{
					int next = (now / 10) + ((now % 10) * 1000);
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						how[next] = cmd[i];
						from[next] = now;
						dist[next] = dist[now] + 1;
					}
				}
			}
		}	
		print(n1, n2);
		cout << endl;
	}
	return 0;
}