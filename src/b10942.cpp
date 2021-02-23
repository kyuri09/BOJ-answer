#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int n, m;
int a[2000];
int d[2000][2000];

   //top-down
int go(int i, int j) 
{
    if (i == j) {
        return 1;
    }
    else if (i + 1 == j) {
        if (a[i] == a[j]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    if (a[i] != a[j]) {
        return d[i][j] = 0;
    }
    else {
        return d[i][j] = go(i + 1, j - 1);
    }
}
int main(void)
{
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
        scanf("%d", &a[i]);
	}
	
    scanf("%d", &m);
	
	memset(d, -1, sizeof(d));

	while (m--)
	{
		int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", go(s - 1, e - 1));
	}
	return 0;
}

//bottom-up
/*
int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        d[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1]) d[i][i + 1] = 1;
    }

    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int k = i + j - 1;
            if (a[j] == a[k] && d[j + 1][k - 1]) d[j][k] = 1;
        }
    }
    scanf("%d", &m);
    while (m--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s - 1][e - 1]);
    }
    return 0;
}*/