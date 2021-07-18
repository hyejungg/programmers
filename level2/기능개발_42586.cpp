#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int day = 0;
    queue<int> q; //배포까지 작업 일

    for (int i = 0; i < progresses.size(); i++)
    {
        int temp = 100 - progresses[i];
        if (temp % speeds[i] == 0)
            q.push(temp / speeds[i]);
        else
            q.push(temp / speeds[i] + 1);
    }

    while (!q.empty())
    {
        int feature = 1; //loop돌 때마다 1로 초기화
        int now = q.front();
        q.pop();

        while (1)
        {
            if (!q.empty() && now >= q.front())
            {
                feature++;
                q.pop();
            }
            else
            {
                answer.push_back(feature);
                break;
            }
        }
    }

    return answer;
}