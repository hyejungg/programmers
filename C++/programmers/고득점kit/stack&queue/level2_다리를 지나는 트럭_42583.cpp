#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int sec = 0;        //초
    int sum_weight = 0; //다리 위 트럭의 무게 합
    queue<int> q;       //다리 위 트럭

    int idx = 0;
    while (1)
    {
        if (idx == truck_weights.size())
        {
            sec += bridge_length;
            break;
        }

        int now = truck_weights[idx];
        sec++; //1초 증가

        if (sum_weight + now <= weight)
        {
            q.push(truck_weights[idx++]); //다음 트럭 넣어
            sum_weight += now;
        }
        else
        {
            q.push(0); //공기 넣어
        }

        if (q.size() == bridge_length)
        {
            sum_weight -= q.front();
            q.pop();
        }
    }

    return sec;
}