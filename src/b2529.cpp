#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
bool check(vector<int> &num, vector<char> &ine)
{
	for (int i = 0; i < k; i++)
	{
		if (ine[i] == '<' && num[i] > num[i + 1])
			return false;
		if (ine[i] == '>' && num[i] < num[i + 1])
			return false;
	}
	return true;
}
int main(void)
{

	cin >> k;
	
	vector<char> ine(k);

	for (int i = 0; i < k; i++)
	{
		cin >> ine[i];
	}

	vector<int> mini(k + 1);
	vector<int> maxi(k + 1);
	

	for (int i = 0; i <= k; i++)
	{
		mini[i] = i;
		maxi[i] = 9 - i;
	}
	
	do
	{
		if (check(mini, ine)) break;
	} while (next_permutation(mini.begin(), mini.end()));

	do
	{
		if (check(maxi, ine)) break;
	} while (prev_permutation(maxi.begin(), maxi.end()));

	for (int i = 0; i < k + 1; i++)
	{
		cout << maxi[i];
	}
	
	cout << "\n";
	for (int i = 0; i < k + 1; i++)
	{
		cout << mini[i];
	}
	cout << "\n";

	return 0;
}