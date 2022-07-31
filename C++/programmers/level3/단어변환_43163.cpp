#include <string>
#include <vector>
using namespace std;

int answer = 100000;
bool visit[51] = {
    false,
}; //방문 여부

void dfs(string begin, const string target, vector<string> &words, int result)
{
    if (target == begin)
    {
        answer = min(answer, result);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (begin[j] != words[i][j]) //1개라도 다르다면
                cnt++;
            if (cnt == 2) //1개씩만 달라도 변환 가능하니까 break
                break;
        }

        if (cnt == 1)
        {
            if (visit[i] == false)
            {
                visit[i] = true; //한 번 거쳐 만족한 단어이므로 제외
                dfs(words[i], target, words, result + 1);
                visit[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    //dfs로 begin과 words를 비교하여 1개라도 다르면 변환시킴
    dfs(begin, target, words, 0);
    if (answer == 100000)
        answer = 0;
    return answer;
}
