//dfs 버전 ... 재귀이용
#include <string>
#include <vector>
using namespace std;

bool visit[200] = {
    false,
};

void dfs(int start, vector<vector<int>> computers)
{
    visit[start] = true; //방문
    for (int i = 0; i < computers[start].size(); i++)
    {
        if (i != start && !visit[i] && computers[start][i] == 1)
        { //대각선, 방문 제외 + 이번에 방문할 친구가 1이라면
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < computers.size(); i++)
    { //행별로 bfs 탐색
        if (visit[i])
            continue;
        else
        {
            dfs(i, computers);
            answer++; //깊이우선탐색이니까 여기서 호출하는 dfs의 수 == 네트워크 수
        }
    }

    return answer;
}
//bfs 버전 ... queue 이용
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visit[200] = {
    false,
};

void bfs(int start, vector<vector<int>> computers)
{
    visit[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < computers[start].size(); i++)
        {
            if (!visit[i] && computers[front][i] == 1)
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < computers.size(); i++)
    { //행별로 bfs 탐색
        if (visit[i])
            continue;
        else
        {
            bfs(i, computers);
            answer++; //깊이우선탐색이니까 여기서 호출하는 dfs의 수 == 네트워크 수
        }
    }

    return answer;
}