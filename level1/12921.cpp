#include <vector>
using namespace std;

//에라토스테네스의 체 == 작은 수의 배수부터 배열을 지워가며 소수(자기 자신으로만 떨어지는)를 찾는

int solution(int n)
{
    int answer = 0;
    vector<bool> chk(n + 1, 0); //n+1개 짜리 배열 생성, 0으로 초기화

    //에라토스테네스의 체를 이용하여 소수 구함
    for (int i = 2; i <= n; i++)
    {
        if (chk[i])
            continue;

        for (int j = i + i; j <= n; j += i)
        { //2의 배수부터 소수가 아닌 애들 체크
            chk[j] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (!chk[i])
        { //체크가 안된 수 == 소수
            answer++;
        }
    }

    return answer;
}