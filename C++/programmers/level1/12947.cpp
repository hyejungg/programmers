#include <string>
#include <vector>
#include <iostream>

//조건: (주어진 수)%(자릿수의 합) == 0 이어야 함

using namespace std;

bool solution(int x)
{
    bool answer = false;
    int temp = x;
    int sum = 0; //자릿수의 합
    //1. 자릿수의 합 구하기
    while (temp != 0)
    {
        sum = sum + temp % 10; //마지막 일의자리
        temp = temp / 10;
    }
    //2. 하샤드 수인지 구하기
    if (x % sum == 0)
        answer = true;
    else
        answer = false;

    return answer;
}