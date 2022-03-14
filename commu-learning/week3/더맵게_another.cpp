// 큐 사용 안하고 백터에서 지우는 방식
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(),scoville.end());

    while(scoville[0] < K) {
        if(scoville.size() == 1){
            answer = -1;
            scoville[0] = K;
        }
        else{
        scoville[1] = scoville[0] + scoville[1]*2;
        scoville.erase(scoville.begin());
        answer++;
        sort(scoville.begin(),scoville.end());}
    }

    if(scoville.size() == 1 && scoville[0] < K){
        answer = -1;
    }
    return answer;
}
