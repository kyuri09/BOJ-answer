#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int go(vector<int>& ball)
{
	int x = ball.size();
	if (x == 2) return 0;
	int ans = 0;
	for (int i = 1; i < x - 1; i++)
	{
		int energy;
		energy = ball[i - 1] * ball[i + 1];
		vector<int> tmp(ball);
		tmp.erase(tmp.begin() + i);
		energy += go(tmp); 
		if (ans < energy) ans = energy;
	}
	return ans;
}
int main(void)
{
	cin >> n;
	vector<int>ball;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		ball.push_back(x);
	}

	cout << go(ball) << endl;
	return 0;
}