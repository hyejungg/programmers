#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q; //{idx, priorities}
    priority_queue<int> pq; //중요도만 담음
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int idx = q.front().first;
        int priority = q.front().second;
        q.pop();
        
        if(priority != pq.top()) {
            q.push({idx, priority});
        } else {
            answer++;
            pq.pop(); //현재 중요도가 높은 값 빼
            if(idx == location) {
                break;
            }
        }
    }
    
    return answer;
}