#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q; //배포까지 작업할 일

    //우선 큐에 넣어
    for (int i = 0; i < progresses.size(); i++)
    {
        int day = 100 - progresses[i];
        if (day % speeds[i] == 0)
            q.push(day / speeds[i]);
        else
            q.push(day / speeds[i] + 1);
    }

    //q가 빌 때까지 반복
    while (!q.empty())
    {
        int day = 1; //배포 일수
        int now = q.front();
        q.pop();

        while (1)
        {
            if (!q.empty() && q.front() <= now)
            {
                day++;
                q.pop();
            }
            else
            {
                answer.push_back(day);
                break;
            }
        }
    }

    return answer;
}