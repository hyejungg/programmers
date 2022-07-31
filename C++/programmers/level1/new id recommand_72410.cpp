#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    string temp = "";

    //1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    //2단계
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer += new_id[i];
    }

    //3단계
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == '.')
        {
            int cnt = 0;
            for (int j = i + 1; j < answer.size(); j++)
            {
                if (answer[j] == '.')
                    cnt++;
                else
                    break;
            }
            if (cnt > 0)
            {
                temp += '.'; //1개로 치환
                i += cnt;
            }
            else
                temp += answer[i];
        }
        else
            temp += answer[i];
    }

    //4단계
    if (temp.front() == '.')
        temp.erase(temp.begin());
    if (temp.back() == '.')
        temp.pop_back();

    //5단계
    if (temp.empty())
        temp += "a";

    //6단계
    if (temp.size() >= 16)
        temp = temp.substr(0, 15);
    if (temp.back() == '.')
        temp.pop_back();

    //7단계
    while (temp.size() <= 2)
        temp.push_back(temp.back());

    return temp;
}