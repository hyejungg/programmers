#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size(); //오름차순 정렬
}

vector<int> solution(string s)
{
    vector<int> answer;
    vector<string> temp; //각 자리별 배열

    int idx = 0;
    string tmp = "";
    int cnt = 0;
    while (idx < s.size())
    {
        if (s[idx] == '{')
            cnt++;
        else if (s[idx] == '}')
        {
            if (cnt == 2)
            {
                temp.push_back(tmp);
                tmp = ""; //초기화
            }
            cnt--;
        }
        else if (cnt == 2)
            tmp += s[idx];
        idx++;
    }

    sort(temp.begin(), temp.end(), cmp);
    answer.push_back(stoi(temp[0])); //1개 넣어둠

    for (int i = 1; i < temp.size(); i++)
    { //다음꺼부터 탐색

        vector<string> a;
        string t = "";
        stringstream ss(temp[i]);
        while (getline(ss, t, ','))
        {
            a.push_back(t); //,를 구분하여 a에 담음
        }

        for (int j = 0; j < a.size(); j++)
        {
            int elem = stoi(a[j]);
            auto itr = find(answer.begin(), answer.end(), elem); //elem이 있나 탐색
            if (itr == answer.end())
                answer.push_back(elem);
        }
    }

    return answer;
}