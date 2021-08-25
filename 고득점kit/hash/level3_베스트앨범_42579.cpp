#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> mt;           //first : 장르, second : 장르별로 총 재생 횟수
    map<string, map<int, int>> mp; //first: 장르, second.first : idx, second.second : 재생횟수

    //필요 map 초기화
    for (int i = 0; i < genres.size(); i++)
    {
        mt[genres[i]] += plays[i];   //각 장르별 total 스트리밍 값 저장
        mp[genres[i]][i] = plays[i]; //각 장르별, idx, 재생횟수
    }

    //장르가 없어질 때까지 반복
    while (mt.size() > 0)
    {
        string genre = "";
        int max = 0;

        //장르 중 가장 큰 값 찾기
        for (auto t : mt)
        {
            if (max < t.second)
            {
                max = t.second;
                genre = t.first;
            }
        }

        //2개 인덱스만 뽑아내기
        for (int i = 0; i < 2; i++)
        {
            int play = 0;
            int idx = -1;

            //해당 장르 중 가장 큰 값 찾기
            for (auto p : mp[genre])
            {
                if (play < p.second)
                {
                    play = p.second;
                    idx = p.first;
                }
            }

            if (idx == -1)
                break; //예외처리

            answer.push_back(idx);
            mp[genre].erase(idx);
        }
        mt.erase(genre);
    }

    return answer;
}