#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

const int INF = 987654321;
const int MAX = 101;

set<int> edges[MAX]; //그래프를 인접행렬로 나타내기 위함

int getLength(int node, vector<vector<int>> &wires)
{
    int length = 0;
    queue<int> q;
    q.push(node);

    bool visit[MAX] = {
        false,
    };
    visit[node] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        length++;

        //현재 node(cur)와 연결된 자식 노드들 중 방문하지 않은 애들을 방문하여 연결된 노드의 개수를 구함
        for (auto next : edges[cur])
        {
            if (!visit[next])
            {
                q.push(next);
                visit[next] = true;
            }
        }
    }
    //해당 node와 연결된 자식 노드들의 개수를 return
    return length;
}

int solution(int n, vector<vector<int>> wires)
{
    //모든 전선 정보를 edges에 담음
    for (auto w : wires)
    {
        edges[w[0]].insert(w[1]);
        edges[w[1]].insert(w[0]);
    }

    int answer = INF;

    //모든 전선 정보를 탐색
    for (auto w : wires)
    {
        edges[w[0]].erase(w[1]);
        edges[w[1]].erase(w[0]);

        //w[0]과 w[1] 노드 중 연결된 자식 노드들의 개수를 구하고, abs(개수의 차이)를 answer에 저장
        answer = min(answer, abs(getLength(w[0], wires) - getLength(w[1], wires)));

        edges[w[0]].insert(w[1]);
        edges[w[1]].insert(w[0]);
    }

    return answer;
}

//[참고](https://jaimemin.tistory.com/1987)