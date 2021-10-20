#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i];
        }
        else
        {
            if (s[i] == 'z')
            {
                answer += '0';
                i += 3;
            }
            else if (s[i] == 'o')
            {
                answer += '1';
                i += 2;
            }
            else if (s[i] == 't')
            {
                if (s.substr(i, 3) == "two")
                {
                    answer += '2';
                    i += 2;
                }
                else
                {
                    answer += '3';
                    i += 4;
                }
            }
            else if (s[i] == 'f')
            {
                if (s.substr(i, 4) == "four")
                {
                    answer += '4';
                }
                else
                {
                    answer += '5';
                }
                i += 3;
            }
            else if (s[i] == 's')
            {
                if (s.substr(i, 3) == "six")
                {
                    answer += '6';
                    i += 2;
                }
                else
                {
                    answer += '7';
                    i += 4;
                }
            }
            else if (s[i] == 'e')
            {
                answer += '8';
                i += 4;
            }
            else if (s[i] == 'n')
            {
                answer += '9';
                i += 3;
            }
        }
    }

    return stoi(answer);
}
//정규식을 이용한 풀이
#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    //regex_replace : 문자열(s)에서 regex(해당 패턴을 가진 문자열, 변경문자열)로 변경
    s = regex_replace(s, regex("zero", "0"));
    s = regex_replace(s, regex("one", "1"));
    s = regex_replace(s, regex("two", "2"));
    s = regex_replace(s, regex("three", "3"));
    s = regex_replace(s, regex("four", "4"));
    s = regex_replace(s, regex("five", "5"));
    s = regex_replace(s, regex("six", "6"));
    s = regex_replace(s, regex("seven", "7"));
    s = regex_replace(s, regex("eight", "8"));
    s = regex_replace(s, regex("night", "9"));
    return stoi(s);
}