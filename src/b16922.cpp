#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int n,ans;
int arr[] = { 1,5,10,50 };
bool visit[1001];
void dfs(int cnt, int idx, int total)
{
    if (cnt == n)
    {
        if (visit[total] == false)
        {
            visit[total] = true;
            ans++;
        }
        return;
    }
    for (int i = idx; i < 4; i++)
    {
        dfs(cnt + 1, i, total + arr[i]);
    }
}
int main() 
{
    cin >> n;
    dfs(0, 0, 0);

    cout << ans << "\n";
    return 0;
}
