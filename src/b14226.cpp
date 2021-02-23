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

int s;
bool visited[1001][1001];
int main()
{
	cin >> s;

	queue<tuple<int, int, int>> q;

	q.push(make_tuple(1, 0, 0));
	visited[1][0] = true;
	while (!q.empty())
	{
		int screen, clip, time;
		tie(screen, clip, time) = q.front();
		q.pop();

		if (screen == s)
		{
			cout << time;
			break;
		}
		if (screen > 0 && screen < 1001)
		{
			if (!visited[screen][screen])
			{
				q.push(make_tuple(screen, screen, time + 1));
				visited[screen][screen] = true;
			}
			if (!visited[screen - 1][clip])
			{
				q.push(make_tuple(screen - 1, clip, time + 1));
				visited[screen - 1][clip] = true;
			}
			if (clip > 0 && screen + clip < 1001 && !visited[screen + clip][clip])
			{
				q.push(make_tuple(screen + clip, clip, time + 1));
				visited[screen + clip][clip] = true;
			}
		}
	}

	return 0;
}