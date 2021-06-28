#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int cnt = 0;                                           //lottos-win_nums 일치하는 수
    int zero_cnt = count(lottos.begin(), lottos.end(), 0); //lotoos의 0의 개수

    for (auto l : lottos)
    {
        if (find(win_nums.begin(), win_nums.end(), l) != win_nums.end())
            cnt++;
    }

    if (cnt >= 2)
    {                                           //일차하는 개수가 2개 이상일 때
        answer.push_back(7 - (cnt + zero_cnt)); //최고
        answer.push_back(7 - cnt);              //최저
    }
    else
    {
        if (cnt + zero_cnt <= 1)
            answer.push_back(6);
        else
        {
            answer.push_back(7 - (cnt + zero_cnt)); //최고
        }
        answer.push_back(6); //최저
    }
    return answer;
}