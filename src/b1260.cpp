#include <iostream>
#include <queue>

using namespace std;

int mat[1001][1001];	//�������
int visit[1001];		//�湮
int n, m, v;		//��尳��, ��������,�����ҳ��

void dfs(int v)
{
	printf("%d ", v);

	visit[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 1 || mat[v][i] == 0)	//��忡 �湮�߰ų� ���������� ������ 
			continue;							//for�� ��� ���鼭 ��� ã��
		dfs(i);				//���
	}
}
void bfs(int v)
{
	queue<int> q;			//bfs �� q ���

	q.push(v);				//ť�� ó�� ���� ��� �־��� 
	
	visit[v] = 0;		//�湮�� ��� 0���� �ٲ�(dfs���� �̹� 1�� �ٲ�)

	while (!q.empty())			//ť�� ������� ���������� ���� ���� 
	{
		v = q.front();			// ���� ������� v�� �� �־���
		printf("%d ", q.front());
		q.pop();	//���� ������� pop ����
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0 || mat[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}

	}
	
}
int main(void)
{
	int x, y;
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	dfs(v);
	printf("\n");
	bfs(v);
	printf("\n");
}
