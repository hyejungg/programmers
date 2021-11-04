#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    // 3부터 시작하면 tc3, 4 실패. //2부터 시작해도 n이 홀수라면 나머지가 1이 나올 수 있음
    for (int i = 2; i < n; i++)
    {
        if (n % i == 1)
            return i;
    }
}