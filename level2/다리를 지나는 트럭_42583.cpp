#include <string>
#include <vector>
#include <queue>
using namespace std;

//1초에 1대

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;       //경과 초
    int sum_weight = 0;   //다리 위 트럭의 무게 합
    queue<int> on_bridge; //다리 위 트럭

    int idx = 0;
    while (1)
    {
        //마지막 트럭까지 올렸다면, bridge_length를 더한 후 종료
        if (idx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        int temp = truck_weights[idx];
        answer++;

        if (sum_weight + temp <= weight)
        {
            on_bridge.push(truck_weights[idx++]);
            sum_weight += temp;
        }
        else
        {
            on_bridge.push(0); //다리에 올라갈 수 없으면 0을 넣어 초만 증가하도록
        }

        //최대 올릴 수 있는 개수까지 q에 담겨있다면
        if (on_bridge.size() == bridge_length)
        {
            sum_weight -= on_bridge.front();
            on_bridge.pop();
        }
    }

    return answer;
}