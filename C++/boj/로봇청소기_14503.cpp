#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50;

//북 동 서 남 (y, x)
pair<int, int> moveDir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
int R, C, D;
int graph[MAX][MAX];
int result = 0;

void BFS()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{R, C}, D});

    while (!q.empty())
    {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int dir = q.front().second;
        if (graph[nowY][nowX] == 0)
        {
            //벽과 구분 위해
            graph[nowY][nowX] = 2;
            result++;
        }
        q.pop();

        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            //좌회전을 위해 모듈러 연산
            int nextDir = (dir + (3 - i)) % 4;
            int nextY = nowY + moveDir[nextDir].first;
            int nextX = nowX + moveDir[nextDir].second;

            if (0 > nextY || nextY >= N || 0 > nextX || nextX >= M)
            {
                continue;
            }
            if (graph[nextY][nextX] == 0)
            {
                q.push({{nextY, nextX}, nextDir});
                flag = true;
                break;
            }
        }

        //네 방향 다 청소되어 있는 경우
        if (!flag)
        {
            int beforeY = nowY - moveDir[dir].first;
            int beforeX = nowX - moveDir[dir].second;

            if (0 > beforeY || beforeY >= N || 0 > beforeX || beforeX >= M)
            {
                continue;
            }
            if (graph[beforeY][beforeX] != 1)
            {
                q.push({{beforeY, beforeX}, dir});
            }
            else
            {
                break;
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;
    cin >> R >> C >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }
    BFS();
    cout << result;
    return 0;
}
