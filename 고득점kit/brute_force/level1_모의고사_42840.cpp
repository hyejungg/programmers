#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int one[5] = {1, 2, 3, 4, 5};
int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int max(int a, int b)
{
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;      //정답을 맞춘 사람들
    vector<int> score(3, 0); //각 one,two,three 별로 맞춘 개수 저장

    //문제를 돌면서 맞춘 사람을 카운트
    for (int i = 0; i < answers.size(); i++)
    {
        if (one[i % 5] == answers[i])
            score[0]++;
        if (two[i % 8] == answers[i])
            score[1]++;
        if (three[i % 10] == answers[i])
            score[2]++;
    }

    int max_score = max(max(score[0], score[1]), score[2]);

    //오름차순으로 비교하며 값 넣기
    for (int i = 0; i < 3; i++)
        if (score[i] == max_score)
            answer.push_back(i + 1);

    return answer;
}