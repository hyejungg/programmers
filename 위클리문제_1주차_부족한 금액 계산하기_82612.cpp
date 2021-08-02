#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for (int i = 1; i <= count; i++)
    { //count 번 진행
        answer += (price * i);
    }

    return answer > money ? (answer - money) : 0;
}