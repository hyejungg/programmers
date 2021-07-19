#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000000

vector<pair<int, int>> v[51]; //idx : start_node, first: end_node, second : 두 노드간 거리
int dp[51];                   // = {MAX, }; (생성과 동시에 초기화하여 오류발생) //최소 비용 담은 배열

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    fill(&dp[0], &dp[50] + 1, MAX); //fill로 초기화해야 오류발생 X

    for (int i = 0; i < road.size(); i++)
    {
        //무방향(양방향) 고려하여 초기화
        v[road[i][0]].push_back({road[i][1], road[i][2]});
        v[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    //dijkstra를 통해 최소비용 탐색
    dp[1] = 0;

    priority_queue<pair<int, int>> pq; //우선순위 큐 //first: 거리 ,second : 현재 node
    pq.push({0, 1});

    while (!pq.empty())
    {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (dp[now] < dist) //현재 노드의 비용이 dist(음수)보다 작다면, continue
            continue;

        //현재노드와 연결된 노드의 dist 구함
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i].first;
            int nextDist = dist + v[now][i].second;
            if (nextDist < dp[next])
            {
                dp[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }

    //1번 노드부터 탐색했으므로 1~N까지
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] <= K)
            answer++;
    }

    return answer;
}