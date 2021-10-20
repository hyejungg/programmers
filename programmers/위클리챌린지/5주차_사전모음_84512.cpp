#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> v = {"A", "E", "I", "O", "U"};
set<string> s; //중복을 제거하고 담아 둘 변수

//v로 만들 수 있는 모든 조합을 s에 담음
void init(string str)
{
    if (str.size() > 5)
        return;
    s.insert(str);

    for (int i = 0; i < 5; i++)
        init(str + v[i]);
}

int solution(string word)
{
    int answer = 0;

    for (int i = 0; i < 5; i++)
        init(v[i]);

    //s를 돌면서 word랑 일치하는 값을 찾아 idx 반환
    int idx = 1;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == word)
        {
            answer = idx;
            break;
        };
        idx++;
    }

    return answer;
}