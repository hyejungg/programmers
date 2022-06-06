#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0; //섞은 횟수
int getScoville(int a, int b){
    ++answer;
    return a + (b * 2);
}

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); //오름차순 pq 생성 (scoville 복사)
    
    while(pq.size() >= 2 && pq.top() < K) {
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        
        int newNum = getScoville(num1, num2);
        pq.push(newNum);
    }
    
    return (pq.top() < K)? -1 : answer;
}