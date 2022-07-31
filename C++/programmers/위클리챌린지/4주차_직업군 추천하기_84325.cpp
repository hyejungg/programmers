#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first; //사전순
    else
        return a.second > b.second; //각 언어별 점수 순
}

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "";
    vector<pair<string, int>> jobsScores;

    for (int str = 0; str < table.size(); str++)
    {
        map<string, int> info; //first : 직업군, second : 각 점수
        int num = 5;           //5로 초기화
        int cnt = 0;           //직업군만 저장하기 위한 카운트 값
        string nowJobs = "";

        //행 별로 공백을 기준으로 값 보관
        istringstream ss(table[str]);
        string buffer;
        while (getline(ss, buffer, ' '))
        {
            if (cnt == 0)
            {
                nowJobs = buffer; //현재 행의 job이 뭔지 보관
                cnt++;
            }
            else
                info.insert({buffer, num--});
        }

        int score = 0;
        //language 별로 값 계산
        for (int i = 0; i < languages.size(); i++)
        {
            for (auto s : info)
            {
                if (s.first == languages[i])
                {
                    score += (preference[i] * s.second);
                }
            }
        }
        jobsScores.push_back({nowJobs, score}); //현재 잡의 언어별 총 값 보관
    }

    sort(jobsScores.begin(), jobsScores.end(), cmp); //점수를 기준으로 내림차순 정렬

    answer = jobsScores[0].first;

    return answer;
}