#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, k;
int map[1000][1000];
int dist[1000][1000][11][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main(void)
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    dist[0][0][0][0] = 1;
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 0));
    while (!q.empty())
    {
        int x, y, z, night;
        tie(x, y, z, night) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (map[nx][ny] == 0 && dist[nx][ny][z][1-night] == 0)
            {
                dist[nx][ny][z][1-night] = dist[x][y][z][night] + 1;
                q.push(make_tuple(nx, ny, z,1-night));
            }
            if (map[nx][ny] == 1 && dist[nx][ny][z + 1][1-night] == 0 && z + 1 <= k&&night==0)
            {
                dist[nx][ny][z + 1][1-night] = dist[x][y][z][night] + 1;
                q.push(make_tuple(nx, ny, z + 1,1-night));
            }
        }
        if (dist[x][y][z][1 - night] == 0)
        {
            dist[x][y][z][1 - night] = dist[x][y][z][night] + 1;
            q.push(make_tuple(x, y, z, 1 - night));
        }
    }
    int ans = -1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (dist[n - 1][m - 1][j][i] == 0) continue;
            if (ans == -1)
                ans = dist[n - 1][m - 1][j][i];
            else if (ans > dist[n - 1][m - 1][j][i])
                ans = dist[n - 1][m - 1][j][i];
        }

    }
    cout << ans << endl;
    return 0;
}