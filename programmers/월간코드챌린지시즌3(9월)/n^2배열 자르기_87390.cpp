#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    // left, right <= n^2이므로 int는 시간 초과
    for (long long i = left; i <= right; i++)
    {
        //모듈러 연산 이용
        int divisor = i / n;
        int mod = i % n;

        answer.push_back((divisor < mod ? mod : divisor) + 1);
    }
    return answer;
}