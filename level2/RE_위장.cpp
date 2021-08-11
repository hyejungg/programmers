#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m; //first : 종류, second : 옷의 수

    //종류 수만큼 count
    for (int i = 0; i < clothes.size(); i++)
        m[clothes[i][1]]++;

    for (auto c : m)
    {
        answer *= (c.second + 1);
    }
    answer--;

    return answer;
}