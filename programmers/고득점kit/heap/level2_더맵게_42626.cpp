#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    if (scoville.size() < 2)
        return -1; //예외처리(2개는 있어야 하니까)

    //가장 낮은 값을 우선 순위로 두고 담아둠
    for (auto s : scoville)
        pq.push(s);

    while (pq.top() < K && pq.size() > 1)
    {
        int one = pq.top(); //가장 작은 값
        pq.pop();
        int two = pq.top(); //두 번째로 작은 값
        pq.pop();

        answer++; //섞는 횟수 증가
        pq.push(one + (two * 2));
    }

    //while문 종료 후 가장 작은 값이 K보다 작다면 스코빌 지수를 만들 수 없음
    if (pq.top() < K)
        return -1;

    return answer;
}