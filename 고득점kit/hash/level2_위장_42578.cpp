#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m; //first : 종류, second : 개수

    //종류가 몇 개인지 담아
    for (int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][1]]++;
    }

    for (auto &c : m)
        answer *= (c.second + 1);

    return --answer;
}