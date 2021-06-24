#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    for (int i = 1; i <= n; i++)
    {
        // if (i % 2 != 0) //홀수
        //     answer += "수";
        // else //짝수
        //     answer += "박";

        //삼항연산자 이용
        i % 2 != 0 ? answer += "수" : answer += "박";
    }
    return answer;
}