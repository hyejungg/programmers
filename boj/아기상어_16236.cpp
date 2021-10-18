#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

#define MIN 987654321

int area[21][21] = {
    0,
};
int ans = 0;
int N = 0;
int babyX = 0, babyY = 0, babySize = 2, eatCount = 0;
int eatDistance = 0;
vector<pair<pair<int, int>, int>> Eat;

//상하좌우 탐색을 위한
int visit[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(int x, int y)
{
    eatDistance = MIN;
    Eat.clear();
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        //상하좌우 탐색
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (0 > nextX || N <= nextX || 0 > nextY || N <= nextY)
            {
                continue;
            }
            //자기보다 큰 물고기 자리
            if (visit[nextX][nextY] == 0 && babySize >= area[nextX][nextY])
            {
                visit[nextX][nextY] = visit[nowX][nowY] + 1;

                //자기보다 작은 물고기 냠냠
                if (area[nextX][nextY] > 0 && area[nextX][nextY] < babySize)
                {
                    if (eatDistance >= visit[nextX][nextY])
                    {
                        eatDistance = visit[nextX][nextY];
                        Eat.push_back({{eatDistance, nextX}, nextY});
                    }
                }
                q.push({nextX, nextY});
            }
        }
    }
}

int main()
{
    //input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];

            //아기상어
            if (area[i][j] == 9)
            {
                babyX = i;
                babyY = j;
                area[i][j] = 0; //초기화
            }
        }
    }
    //탐색
    while (1)
    {
        BFS(babyX, babyY);

        if (Eat.empty())
        {
            break;
        }
        else
        {
            sort(Eat.begin(), Eat.end());
            eatCount++;
            ans += Eat[0].first.first;
            area[Eat[0].first.second][Eat[0].second] = 0; //초기화 안하면 시간 초과 발생
            babyX = Eat[0].first.second;
            babyY = Eat[0].second;

            if (babySize == eatCount)
            {
                babySize++;
                eatCount = 0;
            }
        }
    }
    cout << ans;
    return 0;
}