#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool DFS(vector<bool> visit, string start, vector<vector<string>> &tickets, vector<string> &answer, vector<string> &temp, int finishCnt)
{
    temp.push_back(start);

    if (finishCnt == tickets.size())
    {
        answer = temp;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == start && !visit[i])
        {
            visit[i] = true;
            bool success = DFS(visit, tickets[i][1], tickets, answer, temp, finishCnt + 1);
            if (success)
                return true;
            visit[i] = false; //도착지는 곧 출발지가 되어야 하니까 초기화?
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer, temp;

    //오름차순 정렬 (중복 시 알파벳 순서대로 가기 위함)
    sort(tickets.begin(), tickets.end());
    vector<bool> visit(tickets.size(), false);
    DFS(visit, "ICN", tickets, answer, temp, 0); // ICN부터 시작

    return answer;
}