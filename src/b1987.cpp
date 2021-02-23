#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int r, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int go(vector<string>& board, vector<bool>& check, int x, int y)
{
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			if (check[board[nx][ny] - 'A'] == false)
			{
				check[board[nx][ny] - 'A'] = true;
				int next = go(board, check, nx, ny);
				if (ans < next) ans = next;
				check[board[nx][ny] - 'A'] = false;
			}
		}
	}
	return ans + 1;
}
int main(void)
{
	cin >> r >> c;
	vector<string> board(r);
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
		
	}
	vector<bool>check(26);
	check[board[0][0] - 'A'] = true;
	cout << go(board, check, 0, 0) << endl;
}