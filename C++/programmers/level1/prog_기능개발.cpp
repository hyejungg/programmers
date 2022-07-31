#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++){
        int job = 100 - progresses[i]; //남은 진척도
        
        if(job % speeds[i] != 0){
            q.push(job / speeds[i] + 1);
        }else {
            q.push(job / speeds[i]);
        }
    }
    
    while(!q.empty()){
        int day = 1;
        int now = q.front();
        q.pop();
        
        while(1) {
            if(!q.empty() && now >= q.front()){
                ++day;
                q.pop();
            } else {
                answer.push_back(day);
                break;
            }
        }
    }
    
    return answer;
}