#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    map<string, int> dict; //first : w+c, second : idx  ....find()하기 위해 key값을 string으로

    //색인번호 초기화
    for (int i = 1; i <= 26; i++)
    {
        dict.insert({{string(1, (char)i + 64)}, i});
    }

    int idx = 27, i = 0;
    while (i != msg.size())
    {
        string w = "";
        char tmp = msg[i]; //string으로 변환을 위해 사용
        w += tmp;
        char c = msg[i + 1];

        // 다음 글자(c)가 포함된 문자열이 없을 때
        if (dict.find(w + c) == dict.end())
        {
            answer.push_back(dict[w]);
            dict.insert({w + c, idx});
            idx++;
        }
        // 다음 글자(c)가 포함된 문자열이 있을 때, 다음 글자(c)를 추가
        else
        {
            while (dict.find(w + c) != dict.end())
            {
                w += c;
                i += 1;
                c = msg[i + 1];
            }
            answer.push_back(dict[w]);
            dict.insert({w + c, idx});
            idx++;
        }
        i++;
    }

    return answer;
}