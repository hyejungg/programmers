// 처음 대소문자만 고려 한 경우, 10개 테케 중 4개 실패
// 알파벳 개수를 이용한 경우, 성공
#include <string>
using namespace std;

string solution(string s, int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue; // 공백인 경우

        //알파벳 개수 26개를 이용 -> 대, 소문자에 따라 s[i]를 재구성
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (s[i] + n - 'A') % 26 + 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i] + n - 'a') % 26 + 'a';
        }
    }
    return s;
}