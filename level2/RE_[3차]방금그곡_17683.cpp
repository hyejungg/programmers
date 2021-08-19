#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<vector<string>> info(musicinfos.size()); //,별로 곡의 정보를 나눠 보관할 info
    vector<pair<string, int>> included; //조건과 일치하는 음악 제목과 음악 길이(가장 긴 걸 return 해야하므로)

    // ','을 기준으로 곡 정보를 info에 담음
    for (int i = 0; i < musicinfos.size(); i++) {
        string temp = "";
        for (int j = 0; j < musicinfos[i].length(); j++) {
            if (musicinfos[i][j] == ',') {
                info[i].push_back(temp);
                temp = "";
            }
            else
                temp += musicinfos[i][j];
        }
        info[i].push_back(temp);
    }

    // m 의 변경 (반올림 -> 소문자로 변경)
    for (int i = 0; i < m.length(); ) {
        if (m[i] == '#') {
            m[i - 1] = tolower(m[i - 1]);
            m.erase(m.begin() + i);
        }
        else
            i++;
    }
    // info 의 변경 (반올림 -> 소문자로 변경)
    for (int i = 0; i < info.size(); i++) {
        for (int j = 0; j < info[i][3].length(); ) {
            if (info[i][3][j] == '#') {
                info[i][3][j - 1] = tolower(info[i][3][j - 1]);
                info[i][3].erase(info[i][3].begin() + j);
            }
            else
                j++;
        }
    }

    for (int i = 0; i < info.size(); i++) {
        //종료시간 - 시작시간
        int hours = stoi(info[i][1].substr(0, 2)) - stoi(info[i][0].substr(0, 2));
        int minutes = stoi(info[i][1].substr(3, 2)) - stoi(info[i][0].substr(3, 2));
        int time = 60 * hours + minutes; //시간(분) 구하기 (라디오에서 재생된 분)

        //원곡의 음 중 라디오에서 실제 재생된 음
        int n = info[i][3].length(); 
        if (time > n) { //재생 시간 > 악보 정보 == 반복됐다는 뜻
            string temp = "";
            for (int count = 0; count < time; count++)
                temp += info[i][3][count % n]; //반복되는 문자열 생성
            info[i][3] = temp; //info에 덮음
        }
        else if (time < n) //재생 시간 < 악보 정보 == 반복되지 않음
            info[i][3] = info[i][3].substr(0, time); //재생 시간까지만 잘라 info에 덮음

        // 기억하는 음을 포함하는지 여부
        n = info[i][3].length(); //다시 길이를 구함
        if (m.length() > n) // n의 길이보다 m이 크다면 찾을 수 없음 
            continue;
        if (info[i][3].find(m) != string::npos) //m의 값이 존재한다면 //존재하지 않을 경우 npos 반환
            included.push_back(make_pair(info[i][2], time)); //include에 곡제목과 라디오에서 재생된 시간을 담음
    }

    if (included.empty()) //include가 비었다는 건 == 조건에 일치하는 음악이 없음
        return "(None)";
    
    sort(included.begin(), included.end(), cmp); //라디오에 재생된 시간을 기준으로 정렬
    answer = included[0].first; //가장 맨 앞에 있는 값이 재생 시간이 긴 음악
    return answer;
}