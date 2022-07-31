#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int N, M; //N은 행, M은 열
int arr[MAX][MAX] = {
    0,
};

//bfs를 위한
bool visit[MAX][MAX] = {
    false,
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS()
{
    queue<pair<pair<int, int>, int>> q; //x, y, cnt
    //(0,0)에서부터 시작
    q.push({{0, 0}, 1});
    visit[0][0] = true;

    while (!q.empty())
    {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (nowX == N - 1 && nowY == M - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
            {
                continue;
            }

            if (!visit[nextX][nextY] && arr[nextX][nextY] == 1)
            {
                visit[nextX][nextY] = true;
                q.push({{nextX, nextY}, cnt + 1});
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = temp[j] - '0';
        }
    }

    int ans = (arr[0][0] != 0) ? BFS() : 0;
    cout << ans;
}