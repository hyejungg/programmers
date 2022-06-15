#include <string>
#include <vector>
using namespace std;

int getDivisor(int num){
    vector<int> nums;
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            nums.push_back(num);
        }
    }
    return nums.size();
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        int divisor = getDivisor(i);
        
        if(divisor % 2 == 0){
            answer += i;
        } else {
            answer -= i;
        }
    }
    return answer;
}