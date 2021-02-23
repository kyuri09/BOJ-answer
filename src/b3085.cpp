#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<string> bom, int n)
{
	int max = 1;
	int count = 1;

	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = 1; j < n; j++)
		{
			if (bom[i][j] == bom[i][j - 1]) count++;
			else count = 1;
			if (max < count) max = count;
		}
		count = 1;
		for (int j = 1; j < n; j++)
		{
			if (bom[j][i] == bom[j - 1][i]) count++;
			else count = 1;
			if (max < count) max = count;
		}
	}
	return max;

}
int main(void)
{
	int n;
	int tmp, max = 0;

	cin >> n;
	vector<string> bom(n);

	for (int i = 0; i < n; i++)
	{
		cin >> bom[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)		//오른쪽
			{
				swap(bom[i][j], bom[i][j + 1]);
				tmp = check(bom, n);
				if (max < tmp) max = tmp;
				swap(bom[i][j], bom[i][j + 1]);
			}
			if (i + 1 < n)		//아래
			{
				swap(bom[i][j], bom[i + 1][j]);
				tmp = check(bom, n);
				if (max < tmp) max = tmp;
				swap(bom[i][j], bom[i + 1][j]);
			}
		}
	}

	cout << max << endl;
}
