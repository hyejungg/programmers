#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        if (s.empty())
            s.push(str[i]);
        else
        {
            if (s.top() == str[i])
                s.pop(); //꺼내
            else
                s.push(str[i]);
        }
    }

    return s.empty() ? 1 : 0;
}