//재귀 함수 이용할 경우 시간초과 발생
#include <string>
#include <vector>
using namespace std;

int fib(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else
        return fib(n-1) + fib(n-2);
}

int solution(int n) {
    int answer = fib(n);
    return answer;
}
//스택을 이용한 경우, 시간초과 발생
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> s;
    s.push(n);
    int a = 0;
    while(!s.empty()){
        a = s.top();
        s.pop();
        if(a == 0) answer += 0;
        else if(a == 1) answer += 1;
        else{
            s.push(a - 1);
            s.push(a - 2);
        }
    }
    return answer;
}
//동적분할법 이용해도 시간 초과
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    vector<int> v(n, 0);
    v[0] = 0;
    v[1] = 1;
    for(int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}
// 모듈러 연산을 이용 *****최종
/* (a+b)%c = ((a%c) + (b%c))%c
 * ex. (10+1)%3 == (10%3 + 1%3)%3 = 2
 * ----------
 * 피보나치 수에 1234567을 %한 값을 찾음 
*/
#include <string>
#include <vector>
using namespace std;

//피보나치 수를 구하기 위해 2개의 수만 구하면 됨. 배열 생성 -> 시간초과 발생

int solution(int n) {
    int before = 0;
    int after = 1;
    
    int answer = 0;
    for(int i = 2; i <= n; i++){
        answer = ((before % NUM) + (after % NUM)) % NUM;
        before = after; // f(n-2) 갱신
        after = answer; // f(n-1) 갱신
    }
    return answer;
}