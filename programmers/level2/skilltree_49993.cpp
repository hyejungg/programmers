#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    //skill_trees 돌면서 인덱스의 값 비교
    for (auto st : skill_trees)
    {
        vector<int> temp;
        for (auto s : st) //해당 인덱스 내 값의 한 글자마다 비교
            for (auto sk : skill)
            {
                if (sk == s)
                    temp.push_back(s);
            }

        //배열을 꺼내면서 순서에 맞는지 확인
        bool isCheck = true;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != skill[i])
            {
                isCheck = false;
                break;
            }
        }
        if (isCheck)
            answer++;
    }
    return answer;
}