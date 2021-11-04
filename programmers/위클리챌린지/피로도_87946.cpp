#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    vector<int> v;
    for (int i = 0; i < dungeons.size(); i++)
        v.push_back(i);

    do
    {
        int now = k;
        int cnt = 0;

        for (int i = 0; i < dungeons.size(); i++)
        {
            if (dungeons[v[i]][0] > now)
                continue;

            now -= dungeons[v[i]][1];
            cnt++;
        }
        answer = max(answer, cnt);
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}