#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = n;
    for(int idx = 2; idx < n; idx++){
        if(n % idx == 1){
            answer = min(answer, idx);
        }
    }
    return answer;
}