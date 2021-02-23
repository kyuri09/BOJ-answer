#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, k;
int map[1000][1000];
int dist[1000][1000][11];
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
            if (map[nx][ny] == 1 && dist[nx][ny][z + 1] == 0 && z + 1 <= k)
            {
                dist[nx][ny][z + 1] = dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }

        }
    }
    int ans = -1;
    for (int i = 0; i <= k; i++)
    {
        if (dist[n - 1][m - 1][i] == 0) continue;
        if (ans == -1)
        {
            ans = dist[n - 1][m - 1][i];
        }
        else if (ans > dist[n - 1][m - 1][i])
            ans = dist[n - 1][m - 1][i];
    }
    cout << ans << endl;
    return 0;
}