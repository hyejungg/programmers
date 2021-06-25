#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCount = 0;
    int yCount = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
        { //p를 찾은 경우
            pCount++;
        }
        else if (s[i] == 'y' || s[i] == 'Y')
        { //y를 찾은 경우
            yCount++;
        }
        else
        { //p,y모두 없는 경우
            answer = true;
        }
    }

    if (pCount == yCount)
        answer = true;
    else
        answer = false;

    return answer;
}