#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 25

int arr[MAX][MAX] = {
    -1,
};
int N;
int houseCnt;
vector<int> complexCnt;

bool visit[MAX][MAX] = {
    false,
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y)
{
    houseCnt++; //집의 개수 카운트 증가
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        {
            continue;
        }
        if (!visit[nextX][nextY] && arr[nextX][nextY] == 1)
        {
            DFS(nextX, nextY);
        }
    }
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;

    houseCnt++;
    visit[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
            {
                continue;
            }
            if (!visit[nextX][nextY] && arr[nextX][nextY] == 1)
            {
                houseCnt++;
                visit[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }
}

int main()
{
    //input
    cin >> N; //지도의 크기
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = temp[j] - '0';
        }
    }
    /*//(0,0)부터 탐색 - DFS
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				houseCnt = 0;
				DFS(i, j);
				complexCnt.push_back(houseCnt);
			}
		}
	}
	*/
    //(0,0)부터 탐색 - BFS
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && !visit[i][j])
            {
                houseCnt = 0;
                BFS(i, j);
                complexCnt.push_back(houseCnt);
            }
        }
    }

    //houseCnt를 오름차순으로 정렬
    sort(complexCnt.begin(), complexCnt.end());

    //output
    cout << complexCnt.size() << "\n";
    for (auto cnt : complexCnt)
    {
        cout << cnt << "\n";
    }
}