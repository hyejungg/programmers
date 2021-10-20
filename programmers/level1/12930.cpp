//큐를 쓰면 시간 에러 -> 새로 짠 코드
#include <string>
using namespace std;

string solution(string s)
{
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        { //공백일 경우
            answer += s[i];
            idx = 0;
        }
        else
        { //공백이 아닌 경우
            if (idx % 2 == 0)
            { //인덱스가 짝수라면
                s[i] = toupper(s[i]);
            }
            else
            { //인덱스가 홀수라면
                s[i] = tolower(s[i]);
            }
            answer += s[i];
            idx++;
        }
    }
    return answer;
}