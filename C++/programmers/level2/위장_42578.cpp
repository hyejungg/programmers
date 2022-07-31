#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m; //first : 종류, second : 옷의 수

    for (int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][1]]++;
    }

    for (auto a : m)
    {
        /*예를 들어 머리부분 3개고, 눈부분 2개일 때
         ([머리] 입을 수 있는 경우 3가지 + 아무것도 안 입는 경우 1가지) * ([눈] 입을 수 있는 경우 2가지 + 아무것도 안 입는 경우 1가지)
         문제에서 적어도 무언가는 하나는 써야 한다고 했으니 
         모든 부분에 아무것도 안 입는 경우 1가지를 제외*/
        answer *= (a.second + 1);
    }
    answer--; //전부 다 벗은 경우 (불가능 - 제한사항)
    return answer;
}