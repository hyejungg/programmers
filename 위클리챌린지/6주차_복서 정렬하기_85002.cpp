#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> temp; //비교함수에서 무게 기준 정렬 구하기 위함

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.second > b.second.second) //1. 능률 높은 순으로 정렬
        return true;
    else if (a.second.second == b.second.second)
    { //2. 능률이 같을 경우 이긴 횟수 기준으로 정렬
        if (a.second.first > b.second.first)
            return true;
        else if (a.second.first == b.second.first) //3. 이긴 횟수가 같을 경우 무게 기준 정렬
            if (temp[a.first - 1] > temp[b.first - 1])
                return true;
            else if (temp[a.first - 1] == temp[b.first - 1]) //4. 무게 기준도 같을 경우 idx 오름차순 정렬
                return a.first < b.first;
            else
                return false;
        else
            return false;
    }
    else
        return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    temp = weights; //복사

    vector<int> answer;
    vector<pair<int, pair<int, int>>> score; //first : idx, second-first : 이긴 횟수, second-second : 승률

    int bigThen = 0, fight_total = 0;
    double winningRate = 0, winCnt = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        winCnt = 0; //이긴 횟수
        for (int j = 0; j < head2head.size(); j++)
        {
            if (head2head[i][j] != 'N')
                fight_total++;

            if (i != j && head2head[i][j] == 'W')
            { //이김
                winCnt++;
                if (weights[i] < weights[j])
                    bigThen++;
            }
        }
        //승률을 계산해서 배열에 넣음
        if (fight_total > 0)
            winningRate = (winCnt / fight_total) * 1000000000;
        score.push_back({i + 1, {bigThen, winningRate}});

        fight_total = 0;
        winCnt = 0;
        winningRate = 0;
        bigThen = 0; //초기화
    }

    //조건 정렬
    sort(score.begin(), score.end(), cmp);

    for (auto s : score)
        answer.push_back(s.first);

    return answer;
}