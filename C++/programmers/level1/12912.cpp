#include <string>
#include <vector>

using namespace std;

int cmp(int a, int b)
{
    return a > b ? a : b;
}

long long solution(int a, int b)
{
    long long answer = 0;

    if (a == b)
        answer = a;
    else if (a > b)
    {
        for (int i = b; i < a + 1; i++)
            answer += i;
    }
    else if (b > a)
    {
        for (int i = a; i < b + 1; i++)
            answer += i;
    }
    return answer;
    //더 나은 대안
    int A = a < b ? a : b;
    int B = a < b ? b : a;
    for (int i = A; i <= B; i++)
        answer += i;
    return answer;
}
