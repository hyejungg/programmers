solution.cpp
2022-03-02 19:55:17
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;

    //오름차순으로 정렬된 pq 생성하는데 scoville 복사해서 생성
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    //pq가 2이상(scoville의 길이는 2이상) && pq.top() < K 이상일 때까지
   while(pq.size() >= 2 && pq.top() < K){
        int n1 = pq.top(); pq.pop();
        int n2 = pq.top(); pq.pop();
        pq.push(n1 + (n2 * 2));
        ++count; 
    }

    //모든 음식의 스코빌 지수를 k 이상을 만들 수 없는 경우 == pq.top() < K
    return (pq.top() < K) ? -1 : count;
}

//강사풀이추가
