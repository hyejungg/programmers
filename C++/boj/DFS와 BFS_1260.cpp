#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int N, M, V; //N은 정점수, M은 엣지 수, V는 시작노드
int arr[MAX][MAX] = {
    0,
}; //(양방향)

//dfs, bfs를 위한
bool visit[MAX];
queue<int> q;

void DFS(int start)
{
    visit[start] = true;
    cout << start << " ";

    for (int next = 1; next <= N; next++)
    {
        //현재와 연결되어 있으면서 아직 방문하지 않은 경우
        if (!visit[next] && arr[start][next] == 1)
        {
            DFS(next);
        }
    }
}

void BFS(int start)
{
    q.push(start);
    visit[start] = true;
    cout << start << " ";

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        //너비 우선 탐색이므로
        for (int next = 1; next <= N; next++)
        {
            //현재와 연결되어 있으면서 아직 방문하지 않은 경우
            if (!visit[next] && arr[now][next] == 1)
            {
                q.push(next);
                visit[next] = true;
                cout << next << " ";
            }
        }
    }
}

void reset()
{
    for (int i = 1; i <= N; i++)
    {
        visit[i] = false;
    }
}

int main()
{
    //input
    cin >> N >> M >> V;
    for (int i = 1; i <= M; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }

    //output
    reset();
    DFS(V);

    cout << "\n";

    reset();
    BFS(V);
}