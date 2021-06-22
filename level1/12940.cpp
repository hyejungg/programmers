#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m)
{
    vector<int> answer;

    int N, M; //copy변수
    N = n;
    M = m;        //원본data 저장
    int gcd, lcm; //최대공약수, 최소공배수

    //유클리드 호제법을 이용한 최대공약수, 최소공배수 구하는 방법
    while (1)
    {
        int r = n % m;

        if (r == 0)
        {
            gcd = m;
            break;
        }
        n = m;
        m = r;
    }
    lcm = (N / gcd) * (M / gcd) * gcd;

    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}