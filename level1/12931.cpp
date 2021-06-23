#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int temp = n;
    while (temp != 0)
    {
        answer = answer + temp % 10;
        temp /= 10;
    }
    return answer;
}

//신박한 방법 (문자열 이용)
#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    for (int i = 0; i < s.size(); i++)
        answer += (s[i] - '0'); //s[i] - '0'은 아스키코드 값을 이용하여 int로 형변환

    return answer;
}