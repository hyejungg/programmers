#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    vector<vector<string>> info(musicinfos.size()); //musicinfos의 각 행별로 시작시간, 종료시간, 곡제목, 원곡음 보관
    vector<pair<string, int>> included;             //기억하는 음을 포함하는 라디오 재생 곡만 모임

    // musicinfos에서 ,를 기준으로 구분하여 info에 보관
    for (int i = 0; i < musicinfos.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < musicinfos[i].length(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                info[i].push_back(temp);
                temp = "";
            }
            else
                temp += musicinfos[i][j];
        }
        info[i].push_back(temp);
    }

    /* A# C# D# F# G# 는 각각 a,c,d,f,g 로 변경 */
    // m 의 변경
    for (int i = 0; i < m.length();)
    {
        if (m[i] == '#')
        {
            m[i - 1] = tolower(m[i - 1]);
            m.erase(m.begin() + i);
        }
        else
            i++;
    }

    // info 의 변경
    for (int i = 0; i < info.size(); i++)
    {
        for (int j = 0; j < info[i][3].length();)
        {
            if (info[i][3][j] == '#')
            {
                info[i][3][j - 1] = tolower(info[i][3][j - 1]);
                info[i][3].erase(info[i][3].begin() + j);
            }
            else
                j++;
        }
    }

    for (int i = 0; i < info.size(); i++)
    {
        // 시간(분) 구하기
        int hours = stoi(info[i][1].substr(0, 2)) - stoi(info[i][0].substr(0, 2));   //종료 hour - 시작 hour
        int minutes = stoi(info[i][1].substr(3, 2)) - stoi(info[i][0].substr(3, 2)); //종료 minutes - 시작 minutes
        int time = 60 * hours + minutes;                                             //분단위로 구함 (음 하나당 1분)

        // 원곡의 음 중 라디오에서 실제 재생된 음
        /*
         * 진짜 라디오에서 원곡이 어떻게 재생되었는지의 형태를 info[i][3]에 덮음
         */
        int n = info[i][3].length();
        if (time > n) //라디오에서 재생된 시간이 원곡보다 길다면, (반복 재생된 것)
        {
            string temp = "";
            for (int count = 0; count < time; count++)
                temp += info[i][3][count % n];
            info[i][3] = temp;
        }
        else if (time < n) //끝까지 재생되지 못하고 중간에 잘림
            info[i][3] = info[i][3].substr(0, time);

        // 기억하는 음을 포함하는지 여부
        n = info[i][3].length();
        if (m.length() > n)                                  //라디오에서 재생된 형태의 음(n)이 기억하는 음(m)보가 짧다면
            continue;                                        //기억하는 음을 포함하지 못하므로 답이 될 수 업슴
        if (info[i][3].find(m) != string::npos)              //라디오에서 재생된 음악(n)이 기억하는 음(m)보다 길고, 그 음악(m)을 포함하고 있다면
            included.push_back(make_pair(info[i][2], time)); //곡제목, 라디오에서  재생된 길이 저장
    }

    if (included.empty()) //기억하는 음을 포함하는 라디오 재생 곡이 없다면 (None) 반환
        return "(None)";

    sort(included.begin(), included.end(), cmp); //재생된 시간(second)을 기준으로 내림차순 정렬
    answer = included[0].first;
    return answer;
}