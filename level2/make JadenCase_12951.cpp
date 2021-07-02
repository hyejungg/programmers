#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower); //소문자로 모두 변경

    string answer = "";
    bool isCheck = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            isCheck = true;
            answer += " ";
        }
        else
        {
            if (isCheck)
            { //공백 뒤 첫글자만(true)
                if (s[i] >= '0' && s[i] <= '9')
                { //숫자라면
                    answer += s[i];
                }
                else
                { //문자라면
                    s[i] = toupper(s[i]);
                    answer += s[i];
                }
                isCheck = false;
            }
            else
            {
                answer += s[i];
            }
        }
    }
    return answer;
}
//더 나은 대안
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    answer += toupper(s[0]); //맨 첫글자를 대문자로 변경한 후 시작
    for (int i = 1; i < s.size(); i++)
        //이전 글자가 공백이라면 이번 글자는 대문자로, 아닌 경우는 소문자로
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}