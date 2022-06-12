#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int count = 0;
    if(num == 1){
        return 0;
    }
    long lnum = num; //홀수 -> 짝수 -> 홀수 -> 짝수 형태를 계속 반복하면 num이 int 형이라서 오버플로우 발생해요.
    while(lnum != 1){
        if(count == 500){
            break;
        }
        if(lnum % 2 == 0){
            lnum /= 2;
        } else {
            lnum = (lnum * 3) + 1;
        }
        ++count;
    }
    return (count == 500)? -1 : count;
}