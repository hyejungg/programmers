//런타임 에러 발생 -> 비슷한 방법론인데 자료구조를 다른 방식으로 넣는 것으로 구글링하여 해결
/*#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<string, int> si;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<int>> mg; //first : 장르, second : idx
    map<string, int> temp; 
    
    for(int i = 0 ; i < genres.size(); i++){
        temp[genres[i]] += plays[i]; //각 장르별 total 스트리밍 값 저장
        mg[genres[i]].push_back(i); //각 장르별로 idx 값 저장
    }
    
    vector<si> mp(temp.begin(), temp.end());
    sort(mp.begin(), mp.end(), [](si a, si b) {
		return a.second > b.second;
		}); //second 값을 기준으로 정렬
    
    for(int i = 0; i < mp.size(); i++){
        string music = mp[i].first; 
        for(auto a : mg){
            if(a.first == music){ //해당 장르별 고유번호가 큰 순으로 answer에 저장
                vector<int> v = a.second;
                int max = 0; 
                vector<int> maxIdx;
                
                if(v.size() > 1){ //예외처리
                    max = plays[v[0]];
                    maxIdx = v[0];
                } 
                for(int i = 0; i < v.size(); i++){
                    if(max < plays[v[i]]){
                        max = plays[v[i]];
                        maxIdx.push_back(v[i]);
                    }    
                }
                for(int i = 1; i >= 0; i--){ //2개까지만 넣음
                    answer.push_back(maxIdx[i]); 
                }
            }
        }
    }
    return answer;
}
*/
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> mt;           //first : 장르, second : 장르별로 재생 횟수
    map<string, map<int, int>> mp; //first: 장르, second.first : idx, second.second : 재생횟수

    for (int i = 0; i < genres.size(); i++)
    {
        mt[genres[i]] += plays[i];   //각 장르별 total 스트리밍 값 저장
        mp[genres[i]][i] = plays[i]; //각 장르별, idx, 재생횟수
    }

    while (mt.size() > 0)
    {
        string genre{};
        int max{0};

        //장르 중에서 가장 큰 값 찾기
        for (auto a : mt)
        {
            if (max < a.second)
            {
                max = a.second;
                genre = a.first;
            }
        }

        //2곡 넣어야 하므로 2번까지만 반복
        for (int i = 0; i < 2; i++)
        {
            int v = 0;
            int idx = -1;
            //노래 중 가장 큰 값 찾기
            for (auto a : mp[genre])
            {
                if (v < a.second)
                {
                    v = a.second;
                    idx = a.first;
                }
            }
            if (idx == -1)
                break; // 예외처리

            answer.push_back(idx);
            mp[genre].erase(idx);
        }
        //map에서 해당 장르 삭제
        mt.erase(genre);
    }
    return answer;
}