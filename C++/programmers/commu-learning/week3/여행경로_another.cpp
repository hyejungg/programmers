//깔끔한 코드

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int visted [10001];
vector<string> answer;
vector<string> tmp;

void dfs(vector<vector<string>> tickets, string start, int cnt)
{
    tmp.push_back(start);
    //cout << start << " " << cnt << "\n";
    if (cnt == tickets.size() && answer.empty())
    {
        answer = tmp;
        return;
    }
    for (int i=0;i<tickets.size();i++)
    {
        if (visted[i] == 0 && tickets[i][0] == start)
        {
            visted[i] = 1;
            dfs(tickets, tickets[i][1], cnt + 1);
            visted[i] = 0;
        }
    }
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) { 
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 0);
    return answer;
}

//