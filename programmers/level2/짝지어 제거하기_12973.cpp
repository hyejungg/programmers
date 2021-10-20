#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> sta;

    for (int i = 0; i < s.size(); i++)
    {
        if (sta.empty()) //빈 경우, 비지 않은 경우로 두지 않으면 효율성 통과 테스트 불가!!
            sta.push(s[i]);
        else
        {
            if (sta.top() == s[i])
                sta.pop();
            else
                sta.push(s[i]);
        }
    }

    if (sta.empty())
        answer = 1;

    return answer;
}