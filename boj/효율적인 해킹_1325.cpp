#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10001

int N, M;
vector<int> v[MAX];                  //max크기로 초기화
vector<pair<int, int>> possibleHack; //first : 컴퓨터 번호, second : 해킹 가능 수
int possibleHackCount = 1;

bool visit[MAX];
queue<int> q;

void BFS(int i)
{
    visit[i] = true;
    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        for (int j = 0; j < v[i].size(); j++)
        {
            int next = v[i][j];

            if (!visit[next])
            {
                visit[next] = true;
                q.push(next);
                possibleHackCount++; //해킹 가능
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    { //second가 같다면 first의 오름차순 (없으면 틀림)
        return a.first < b.first;
    }
    return false;
}

int main()
{
    //input
    int a = 0, b = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int sp, ep;
        cin >> sp >> ep;
        v[ep].push_back(sp);
    }

    //1번 컴퓨터 ~ N번 컴퓨터까지 해킹 가능 수 탐색
    for (int i = 1; i <= N; i++)
    {
        BFS(i);
        reset();
        possibleHack.push_back({i, possibleHackCount});
        possibleHackCount = 1; //다음 노드 탐색을 위해 초기화
    }

    //해킹 가능 수 내림차순 정렬
    sort(possibleHack.begin(), possibleHack.end(), cmp);

    //output (최대 가능한 해킹 수를 가진 컴퓨터들만 출력)
    for (int i = 0; i < possibleHack.size(); i++)
    {
        if (possibleHack[0].second == possibleHack[i].second)
        {
            cout << possibleHack[i].first << " ";
        }
    }
}