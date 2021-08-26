#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q; //first : idx, second : 우선순위
    priority_queue<int> pq;

    //q와 pq에 담아
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    while (!pq.empty())
    {
        int idx = q.front().first;
        int priorit = q.front().second;
        q.pop();

        if (priorit != pq.top()) //다시 q에 넣어
            q.push({idx, priorit});
        else
        {
            answer++; //차례 ++
            pq.pop(); //pq에서도 꺼내
            if (location == idx)
                break;
        }
    }

    return answer;
}