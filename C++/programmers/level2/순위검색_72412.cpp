#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer(query.size(), 0); //query와 동일한 사이즈인 vector, 0으로 초기화 //안해두면 값 이상함
    map<string, vector<int>> m;          //first : 조건, second : 조건에 해당하는 점수배열 -- 동일 조건에 여러 사람의 점수가 존재할 수 있으므로

    for (int i = 0; i < info.size(); i++)
    {
        string token = "";
        stringstream ss(info[i]);
        vector<vector<string>> str(4, vector<string>(2, "-")); //4x2짜리 문자열 배열 --언어, 직군, 걍략, 소울푸드를 담는 배열
        int index = 0, score = 0;

        //한 개씩 공백을 기준으로 조건을 str에 담음. 점수는 score에
        while (ss >> token)
        {
            if (index < 4)
                str[index++][0] = token;
            else
                score = stoi(token);
        }

        //점수는 점수대로 보관, 각 조건은 합쳐서 하나의 문자열로
        for (int i = 0; i < 2; i++)
        {
            string t1, t2, t3, t4;
            t1 = str[0][i];
            for (int j = 0; j < 2; j++)
            {
                t2 = str[1][j];
                for (int k = 0; k < 2; k++)
                {
                    t3 = str[2][k];
                    for (int l = 0; l < 2; l++)
                    {
                        t4 = str[3][l];
                        m[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }

    //점수를 기준으로 오름차순 진행 (lower_bound)을 위해
    for (auto itr = m.begin(); itr != m.end(); itr++)
        sort(itr->second.begin(), itr->second.end());

    //쿼리를 공백을 기준으로 분할하여 비교
    for (int i = 0; i < query.size(); i++)
    {
        string str = "", token;
        stringstream ss(query[i]);
        int index = 0, score = 0;

        while (ss >> token)
        {
            if (token == "and")
                continue; //and가 나오면 다음 조건으로

            if (index++ < 4)
                str += token;
            else
                score = stoi(token);
        }
        auto itr = lower_bound(m[str].begin(), m[str].end(), score); //이진탐색으로 score와 같거나 큰 반복자 구함
        answer[i] = m[str].size() - (itr - m[str].begin());          //실제 인덱스 위치 찾기 위해 m[str].begin() 빼줌
    }

    return answer;
}