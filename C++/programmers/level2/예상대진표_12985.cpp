#include <iostream>
#include <cmath>
using namespace std;

int nextNum(int num)
{
    return num % 2 == 0 ? num / 2 : (num + 1) / 2;
}

int solution(int n, int a, int b)
{
    int answer = 1; //각 라운드

    //a와 b는 서로 1개 차이, a와 b 중 큰 값이 2의 배수의 경우
    while (!(abs(a - b) == 1 && max(a, b) % 2 == 0))
    {
        a = nextNum(a);
        b = nextNum(b);
        answer++;
    }

    return answer;
}
//더 나은 대안 (비트 연산자 이용)....
#include <iostream>
using namespace std;

// https://mungto.tistory.com/205

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    {
        a = (a + 1) >> 1; // 2 1 1
        b = (b + 1) >> 1; // 4 2 1
        ++answer;
    }

    return answer;
}