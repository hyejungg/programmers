#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    //약수구해서 합 구하기
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) //i는 n의 약수
            answer += i;
    }
    return answer;
}