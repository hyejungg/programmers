#include <iostream>
#include <cstring> //memset
#include <algorithm>
using namespace std;

#define MAX 101
#define MIN 0

int N;
int arr[MAX][MAX];
int maxValue = MIN, minValue = MAX; //최소, 최대 높이

bool visit[MAX][MAX] = {
    false,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int height)
{
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        {
            continue;
        }
        if (arr[nextX][nextY] <= height || visit[nextX][nextY])
        {
            continue;
        }
        visit[nextX][nextY] = true;
        DFS(nextX, nextY, height);
    }
}

int main()
{
    int ans = 1;
    //input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            maxValue = max(maxValue, arr[i][j]);
            minValue = min(minValue, arr[i][j]);
        }
    }

    for (int i = minValue; i < maxValue; i++)
    {
        int cnt = 0;
        memset(visit, false, sizeof(visit));

        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                if (arr[row][col] > i && !visit[row][col])
                {
                    visit[row][col] = true;
                    cnt++;
                    DFS(row, col, i);
                }
            }
        }
        ans = max(ans, cnt);
    }
    //output
    cout << ans;
}