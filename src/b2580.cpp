#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[9][9];
bool row_c[9][9];
bool col_c[9][9];
bool s_board[9][9];

int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}
void go(int step)
{
	if (step == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int x = step / 9;
	int y = step % 9;
	if (board[x][y] != 0) go(step + 1);
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row_c[x][i] == 0 && col_c[y][i] == 0 && s_board[square(x, y)][i] == 0)
			{
				row_c[x][i] = true;
				col_c[y][i] = true;
				s_board[square(x, y)][i] = true;
				board[x][y] = i;
				go(step + 1);
				board[x][y] = 0;
				row_c[x][i] = false;
				col_c[y][i] = false;
				s_board[square(x, y)][i] = false;

			}
		}
	}
	
}
int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)			//ºóÄ­ÀÌ ¾Æ´Ï¸é
			{
				row_c[i][board[i][j]] = true;
				col_c[j][board[i][j]] = true;
				s_board[square(i, j)][board[i][j]] = true;
			}
		}
	}
	go(0);

		
}