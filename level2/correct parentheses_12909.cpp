//1. map을 사용하여 second값끼리 카운팅 해주면 효율성테스트에서 시간 초과 발생
//2. '('로 열고 닫고 카운팅하는 과정에서 카운팅 값 < 0 라면 false인데 예외처리 필요
// #include <string>
// #include <map>
// #include <iostream>

// using namespace std;

// bool solution(string s)
// {
//     bool answer = true;
//     map<int, int> check; //first: idx, second: '('면 1, ')'면 0
//     int ans_cnt = 0;     //괄호 개수

//     if (s.front() == ')')
//         return false; //시작값이 ')'라면 괄호 수가 맞아도 무조건 fasle

//     //문자열 내 문자 하나하나마다 비교
//     for (int i = 0; i < s.size(); i++)
//     {
//         s[i] == '(' ? check.insert({i, 1}) : check.insert({i, 0});
//         ans_cnt += check[i];
//     }
//     answer = (ans_cnt == (s.size() / 2)) ? true : false;
//     return answer;
// }
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int ans_cnt = 0; //괄호 개수

    if (s.front() == ')')
        return false; //시작값이 ')'라면 무조건 fasle

    //문자열 내 문자 하나하나마다 비교
    for (int i = 0; i < s.size(); i++)
    {
        if (ans_cnt < 0)
        { //예외처리
            return false;
        }
        if (s[i] == ')')
        {
            ans_cnt--;
        }
        else if (s[i] == '(')
            ans_cnt++;
    }
    return ans_cnt == 0 ? true : false;
}