/*#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);

    int arr[12] = { 1,2,4 };
    for (int i = 3; i < 11; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", arr[n - 1]);
    }
}*/


#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
int dp[12];
int main()
{
    int t, n;

    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}