#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)     //실패율이 같다면
        return a.first < b.first; //스테이지이름(int) 기준 오름차순
    else
        return a.second > b.second; //실패율(float) 기준 내림차순
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer(N);

    vector<int> all(N);               //스테이지별로 성공, 실패 플레이어들의 도달 횟수
    vector<int> success(N);           //스테이지별로 플레이어들이 성공한 횟수
    vector<pair<int, float>> temp(N); //실패율 저장

    // all, success 업데이트
    for (int i = 0; i < stages.size(); i++)
    {
        for (int j = 0; j < stages[i] && j < N; j++)
            all[j]++;
        for (int j = 0; j < stages[i] - 1; j++)
            success[j]++;
    }

    // 스테이지와 실패율 매칭 pair
    for (int i = 0; i < N; i++)
    {
        // 아무도 도달한적이 없는 스테이지라면, 즉 all[i] = 0 이라면 실패율은 0 으로.
        float fail = (all[i] == 0 ? 0 : (all[i] - success[i]) / (float)all[i]);
        temp[i] = make_pair(i + 1, fail); //스테이지와 실패율 저장
    }

    //실패율 기준 내림차순으로 정렬
    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < N; i++)
        answer[i] = temp[i].first;

    return answer;
}