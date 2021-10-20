#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    if (scoville.size() < 2)
        return -1; //예외처리

    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 pq
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    while (pq.top() < K && pq.size() > 1)
    {
        int s1 = pq.top(); //0번째 값
        pq.pop();
        int s2 = pq.top(); //1번째 값
        pq.pop();

        answer++;
        pq.push(s1 + (s2 * 2));
    }
    if (pq.top() < K)
        return -1; //예외처리

    return answer;
}