#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> m; //first : 완주자 이름, second : 완주 횟수

    //각 완주자 몇 명인지
    for (auto c : completion)
        m[c]++;

    //참여자 중 완주했는지
    for (auto p : participant)
    {
        m[p]--;       //우선 --
        if (m[p] < 0) //0이하라면 완주하지 못한 참여자
            answer += p;
    }

    return answer;
}