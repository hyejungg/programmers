#include <string>
#include <vector>
#include <stack>
using namespace std;

string answer = "";

bool isRight(string str)
{ //올바른 괄호 문자열인지 검사 + answer 완성
    stack<char> s;
    for (auto c : str)
    {
        if (c == '(')
        {
            answer += "(";
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                answer = ""; //초기화
                return false;
            }
            answer += ")";
            s.pop();
        }
    }
    return true;
}

string makeRight(string str)
{
    if (str == "") //빈 문자열인 경우
        return str;

    string u = "", v = "";
    int left = 0, right = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            left++;
        else
            right++;

        if (left == right)
        { //균형잡힌 괄호 문자열이 되었다면 분리
            u = str.substr(0, i + 1);
            v = str.substr(i + 1);
            break;
        }
    }

    if (isRight(u)) //u가 올바르다면, v만 올바르게 만들 때까지 재귀하여 더해서 return
        return u + makeRight(v);
    else
    {                                  //u가 올바르지 않다면,
        string temp = "(";             //4-1
        temp += makeRight(v) + ")";    //4-2, 4-3
        u = u.substr(1, u.size() - 2); //4-4
        for (int i = 0; i < u.size(); i++)
        { //4-4로 첫,마지막 글자 제거 후 남은 문자에 대하여 괄호방향 뒤집음
            if (u[i] == '(')
                temp += ")";
            else
                temp += "(";
        }
        return temp;
    }
}

string solution(string p)
{
    if (isRight(p)) //올바른 괄호 문자열인 경우
        return answer;
    else
        answer = makeRight(p);
    return answer;
}
