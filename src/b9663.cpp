#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool board[15][15];
bool c[15];
bool ldig[40];
bool rdig[40];

bool check(int row, int col)
{
	if (c[col]) return false;
	if (ldig[row + col]) return false;
	if (rdig[col - row + n]) return false;

	return true;
}
int calc(int row)
{
	if (row == n) return 1;

	int count = 0;
	for (int col = 0; col < n; col++)
	{
		if (check(row, col))
		{
			c[col] = true;
			ldig[row + col] = true;
			rdig[col - row + n] = true;
			board[row][col] = true;
			count += calc(row + 1);
			c[col] = false;
			ldig[row + col] = false;
			rdig[col - row + n] = false;
			board[row][col] = false;
		}
	}
	return count;
}
int main(void)
{
	cin >> n;

	cout << calc(0) << endl;
}