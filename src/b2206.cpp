#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;
int map[1000][1000];
int dist[1000][1000][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    dist[0][0][0] = 1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (map[nx][ny] == 0 && dist[nx][ny][z] == 0)
            {
                dist[nx][ny][z] = dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
            if (map[nx][ny] == 1 && dist[nx][ny][z + 1] == 0 && z == 0)
            {
                dist[nx][ny][z + 1] = dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }

        }
    }

    if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0)
    {
        cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    }
    else if (dist[n - 1][m - 1][0] != 0)
    {
        cout << dist[n - 1][m - 1][0];
    }
    else if (dist[n - 1][m - 1][1] != 0)
    {
        cout << dist[n - 1][m - 1][1];
    }
    else
    {
        cout << -1;
    }
    cout << endl;
    return 0;
}