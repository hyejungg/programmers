#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    { //마지막 round는 서로 1이 되므로 while문 종료
        //비트연산을 사용하면 무조건 2의 배수로 줄어듬 !! >> 1
        a = (a + 1) >> 1; //연산 결과 a는 2, 1, 1
        b = (b + 1) >> 1; //연산 결과 b는 4, 2, 1
        answer++;
    }

    return answer;
}