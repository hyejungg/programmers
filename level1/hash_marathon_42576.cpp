#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> m; //first : 참여자 이름, secode : 완주 여부 count

    //완주자 카운트
    for (auto com : completion)
        m[com]++;

    //m을 돌며 완주 여부에 따른 participant의 완주 확인
    for (auto parti : participant)
    {
        m[parti] -= 1;
        if (m[parti] < 0) //완주하지 못한 것으로 봄
            answer += parti;
    }

    return answer;
}