#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int N, M; //전체 사람의 수
int personA, personB;
int famliy[MAX][MAX] = {
    0,
}; //부모, 자식 관계 인접행렬로 구현

bool visit[MAX] = {
    false,
};
int depth[MAX] = {
    0,
};

void DFS(int start)
{
    visit[start] = true;

    if (start == N)
        return;

    for (int i = 1; i <= N; i++)
    {
        if (famliy[start][i] == 1 && !visit[i])
        {
            visit[i] = true;
            depth[i] = depth[start] + 1;
            DFS(i);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        //전체 사람만큼 방문하면서 personB와의 촌수를 구함
        for (int i = 1; i <= N; i++)
        {
            if (famliy[x][i] == 1 && !visit[i])
            {
                visit[i] = true;
                depth[i] = depth[x] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    //intput
    cin >> N;                  //전체 사람 수
    cin >> personA >> personB; //A, B의 촌수를 구해야 함
    cin >> M;                  //부모 자식 관계
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        famliy[a][b] = 1;
        famliy[b][a] = 1;
    }

    DFS(personA);
    //BFS(personA);

    //output
    int ans = (depth[personB] != 0) ? depth[personB] : -1;

    cout << ans;
}