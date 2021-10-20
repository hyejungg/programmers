#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0; //경우의 수 카운트

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = i; j <= n; j++)
        { //1부터 차례로 더해 n을 만들 때
            temp += j;

            if (temp == n)
            {
                answer++;
                break;
            }
            else if (temp > n)
                break;
        }
    }

    return answer;
}