#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.size() == 4 || s.size() == 6)
        {
            if (!isdigit(s[i]))
            {
                answer = false;
                break;
            }
            else
            {
                answer = true;
            }
        }
        else
        {
            answer = false;
        }
    }
    return answer;
}