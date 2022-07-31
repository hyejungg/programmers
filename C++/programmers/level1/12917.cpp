#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<char> vs;
    for (int i = 0; i < s.size(); i++)
    {
        vs.push_back(s[i]);
    }

    sort(vs.begin(), vs.end(), greater<char>()); // 내림차순으로 정렬

    for (int i = 0; i < vs.size(); i++)
    {
        answer += vs[i];
    }

    return answer;
}
//더나은 대안
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    sort(s.begin(), s.end(), greater<char>());
    return s;
}