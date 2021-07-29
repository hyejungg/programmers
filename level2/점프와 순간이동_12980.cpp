#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0)
    {
        if (n % 2 == 0)
        { //짝수라면
            n /= 2;
        }
        else
        {          //홀수라면
            n--;   // 1칸 이동 후
            ans++; //건전지 1개 사용
        }
    }

    return ans;
}