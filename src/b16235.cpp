#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int energy[10][10];
int a[10][10];
vector<int> tree[10][10];
int dx[] = { -1,-1,-1,0,0,1,1,1 };	
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int ans = 0;
void spring_summer()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tree[i][j].size() == 0) continue;
			int dead = 0;
			vector<int> tmp;
			sort(tree[i][j].begin(), tree[i][j].end());		//나이 적은순으로 양분 먹음
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				int age = tree[i][j][k];		//각 칸에 있는 각 나무의 나이
				if (energy[i][j] >= age)		//양분이 나이보다 많으면 먹을 수 있음
				{
					energy[i][j] = energy[i][j] - age;		//나이만큼 양분 먹음->남은 양분
					tmp.push_back(age + 1);			//나무 나이 한살 먹음
				}
				else	 //나이가 양분보다 많아 못먹는 경우
				{
					dead = dead + (age / 2);		//죽은 후 나무 나이/2 만큼 양분됨 
				}
			}
			tree[i][j].clear();		//각 칸 초기화 해주고 나무 업데이트
			for (int k = 0; k < tmp.size(); k++)
			{
				tree[i][j].push_back(tmp[k]);		
			}
			energy[i][j] += dead;		//죽은 나무 양분됨
		}
	}
}
void fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tree[i][j].size() == 0) continue;
			for (int k = 0; k < tree[i][j].size(); k++)	//각 칸에 있는 각 나무 번식 가능한지 체크
			{
				int age = tree[i][j][k];		//각 칸에 있는 각 나무 나이
				if (age % 5 == 0)		//나무가 5의 배수이면
				{
					for (int l = 0; l < 8; l++)		//인접한 8칸으로 번식
					{
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n)
						{
							tree[nx][ny].push_back(1);		//나이가 1인 나무 추가
						}
					}
				}
			}
		}
	}
}
void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			energy[i][j] = energy[i][j] + a[i][j];		//땅에 양분 추가
		}
	}
}
int main(void)
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];		//겨울에 각 칸마다 추가되는 양분의 값
			energy[i][j] = 5;	//초기 양분값 
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;			//나무 위치랑 나이
		tree[x - 1][y - 1].push_back(z);
	}

	for (int i = 0; i < k; i++)
	{
		spring_summer();
		fall();
		winter();
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += tree[i][j].size();
		}
	}
	cout << ans << endl;
}