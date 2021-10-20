//정규표현식으로 풀이
#include <bits/stdc++.h>
using namespace std;
vector<int> score;

void split(string s)
{
    const auto tokenizer = regex("\[0-9]{1,2}[SDT][*#]?"); //?가 붙으면 마지막[*#]는 있어도 되고 없어도 됨

    std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), tokenizer);
    std::regex_iterator<std::string::iterator> rend;

    while (rit != rend)
    {
        auto str = rit->str();
        rit++; //다음으로

        string number_str = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                number_str += str[i];
            else
            {
                int total = atoi(number_str.c_str());
                if (str[i] == 'S')
                    score.push_back(total);
                else if (str[i] == 'D')
                    score.push_back(total * total);
                else if (str[i] == 'T')
                    score.push_back(total * total * total);
                else if (str[i] == '*')
                {
                    score[score.size() - 1] *= 2;
                    if (score.size() > 1)
                        score[score.size() - 2] *= 2;
                }
                else if (str[i] == '#')
                    score[score.size() - 1] *= -1;
            }
        }
    }
}

int solution(string dartResult)
{
    int answer = 0;

    split(dartResult);

    for (auto s : score)
    {
        cout << s << " ";
        answer += s;
    }

    return answer;
}