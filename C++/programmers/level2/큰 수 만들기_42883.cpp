#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    vector<int> num;

    //한 자리씩 num에 넣음
    for (int i = 0; i < number.size(); i++)
    {
        num.push_back(number[i] - '0');
    }

    //그리디하게 탐색
    int start_idx = 0;

    for (int i = 0; i < number.size() - k; i++)
    {
        int max = num[start_idx];
        int idx = start_idx;
        for (int j = start_idx; j <= i + k; j++)
        {
            if (num[j] > max)
            {
                max = num[j];
                idx = j;
            }
        }
        start_idx = idx + 1;
        answer += to_string(max);
    }

    return answer;
}
//더 나은 대안
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    answer = number.substr(k);
    for (int i = k - 1; i >= 0; i--)
    {
        int j = 0;
        do
        {
            if (number[i] >= answer[j])
            {
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }
            else
            {
                break;
            }
        } while (1);
    }

    return answer;
}