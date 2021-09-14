#include <string> 
#include <vector> 
#include <iostream> 
#include <queue> 
#include <algorithm> 
using namespace std; 

int solution(vector<vector<int>> jobs) { 
    int answer = 0; 
    sort(jobs.begin(), jobs.end());  //시간 기준 오름차순 정렬
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //오름차순 pq //first : 작업 시간, second : 기다린 시간
    
    int idx = 0, time = 0; 
    
    while (idx < jobs.size() || !pq.empty()) { 
        if(idx < jobs.size() && time >= jobs[idx][0]) { 
            pq.push({jobs[idx][1], jobs[idx][0]}); 
            idx++; 
            continue; 
        } 
        
        if(!pq.empty()) { 
            time += pq.top().first; // 완료된 시간 
            answer += time - pq.top().second; // 기다린 시간 더해줌 
            pq.pop(); 
        } else //큐가 비었다면, 다음 작업 시간으로 넘김
            time = jobs[idx][0]; 
    } 
    
    return answer / jobs.size(); //평균 구하기 위해 작업 개수로 나눔
}
