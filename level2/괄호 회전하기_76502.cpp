#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        stack<char> sta; //괄호 검사할 stack
        bool right = false;

        //stack에 넣고 검사
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '(' || s[j] == '[' || s[j] == '{')
                sta.push(s[j]);
            else
            {
                if (sta.empty())
                    right = true;
                else
                {
                    if (s[j] == ')' && sta.top() == '(')
                        sta.pop();
                    if (s[j] == '}' && sta.top() == '{')
                        sta.pop();
                    if (s[j] == ']' && sta.top() == '[')
                        sta.pop();
                }
            }
        }
        if (sta.empty() && !right)
            answer++;

        //s 재정의 (왼쪽으로 회전)
        char now = s[0];
        string temp = s.substr(1); //1부터 끝까지 복사 //for문 쓰면 시간 초과
        s = temp + now;            //s 재정의
    }
    return answer;
}