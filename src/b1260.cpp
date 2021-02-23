#include <iostream>
#include <queue>

using namespace std;

int mat[1001][1001];	//인접행렬
int visit[1001];		//방문
int n, m, v;		//노드개수, 간선개수,시작할노드

void dfs(int v)
{
	printf("%d ", v);

	visit[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 1 || mat[v][i] == 0)	//노드에 방문했거나 인접해있지 않으면 
			continue;							//for문 계속 돌면서 경우 찾음
		dfs(i);				//재귀
	}
}
void bfs(int v)
{
	queue<int> q;			//bfs 는 q 사용

	q.push(v);				//큐에 처음 시작 노드 넣어줌 
	
	visit[v] = 0;		//방문한 노드 0으로 바꿈(dfs에서 이미 1로 바꿈)

	while (!q.empty())			//큐가 비어있지 않을때까지 루프 돌림 
	{
		v = q.front();			// 넣은 순서대로 v에 값 넣어줌
		printf("%d ", q.front());
		q.pop();	//넣은 순서대로 pop 해줌
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
