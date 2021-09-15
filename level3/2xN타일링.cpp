#include <string>
#include <vector>
#define NUM 1000000007
using namespace std;

//n일 때, (n-2) + (n-1)
int solution(int n) {
    int answer = 0; //총 경우의 수 
    vector<int> d(n+1, 0); //n일 때 생성 가능한 직사각형을 담는 vetor
    
    d[1] = 1;
    d[2] = 2;
    
    if(n <= 1) return 1; //예외처리 
    if(n >= 3){
        //2 ~ n까지 돌면서, 생성 가능한 직사각형의 개수 저장
        for(int i = 3; i <= n; i++)
            d[i] = (d[i-2] + d[i-1]) % NUM; //수가 커지지 않도록 나눠줌
    }
    
    answer = d[n] % NUM;
    
    return answer;
}
