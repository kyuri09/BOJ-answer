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
			sort(tree[i][j].begin(), tree[i][j].end());		//���� ���������� ��� ����
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				int age = tree[i][j][k];		//�� ĭ�� �ִ� �� ������ ����
				if (energy[i][j] >= age)		//����� ���̺��� ������ ���� �� ����
				{
					energy[i][j] = energy[i][j] - age;		//���̸�ŭ ��� ����->���� ���
					tmp.push_back(age + 1);			//���� ���� �ѻ� ����
				}
				else	 //���̰� ��к��� ���� ���Դ� ���
				{
					dead = dead + (age / 2);		//���� �� ���� ����/2 ��ŭ ��е� 
				}
			}
			tree[i][j].clear();		//�� ĭ �ʱ�ȭ ���ְ� ���� ������Ʈ
			for (int k = 0; k < tmp.size(); k++)
			{
				tree[i][j].push_back(tmp[k]);		
			}
			energy[i][j] += dead;		//���� ���� ��е�
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
			for (int k = 0; k < tree[i][j].size(); k++)	//�� ĭ�� �ִ� �� ���� ���� �������� üũ
			{
				int age = tree[i][j][k];		//�� ĭ�� �ִ� �� ���� ����
				if (age % 5 == 0)		//������ 5�� ����̸�
				{
					for (int l = 0; l < 8; l++)		//������ 8ĭ���� ����
					{
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n)
						{
							tree[nx][ny].push_back(1);		//���̰� 1�� ���� �߰�
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
			energy[i][j] = energy[i][j] + a[i][j];		//���� ��� �߰�
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
			cin >> a[i][j];		//�ܿ￡ �� ĭ���� �߰��Ǵ� ����� ��
			energy[i][j] = 5;	//�ʱ� ��а� 
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;			//���� ��ġ�� ����
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