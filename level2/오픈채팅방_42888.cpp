#include <string>
#include <vector>
#include <map>
#include <sstream> //문자열 공백 기준으로 구분
using namespace std;

vector<pair<bool, string>> enter_v; //first : 0(out)/1(in), second : nickname
map<string, string> user_m;         //first : uid, second : nickname

void split(vector<string> rec)
{
    for (auto r : rec)
    {
        istringstream is(r);
        string stat, id, nickname, s;
        int cnt = 0; //문자열의 공백을 기준으로 idx 값
        while (getline(is, s, ' '))
        {                 // 를 구분
            if (cnt == 0) //Enter, Leave, Change
                stat = s;
            else if (cnt == 1)
            { //uid
                id = s;
                if (stat == "Leave") //나간 경우, 나감여부와 id만 저장
                    enter_v.push_back({0, id});
            }
            else if (cnt == 2)
            { //nickname
                nickname = s;

                if (stat == "Enter")
                {
                    if (user_m.find(id) != user_m.end())
                        user_m[id] = nickname;
                    else
                        user_m.insert({id, nickname});
                    enter_v.push_back({1, id});
                }
                else if (stat == "Change")
                    user_m[id] = nickname; //id 값에 있는 value 갱신
            }
            cnt++;
        }
    }
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    split(record);

    for (auto v : enter_v)
    {
        if (v.first == 0) //나감
            answer.push_back(user_m[v.second] + "님이 나갔습니다.");
        else //들어옴
            answer.push_back(user_m[v.second] + "님이 들어왔습니다.");
    }

    // //@deprecated : 코드 제출할 때 주석처리 해두지 말고, 지우고 돌려야 제출됨! (tc가 많은 경우 시간 초과 발생하나봄)
    // cout << "------------------- vector\n";
    // for(auto a : enter_v){
    //     cout << a.first << " : " << a.second << "\n";
    // }
    // cout << "------------------- map\n";
    // for(auto a : user_m){
    //     cout << a.first << " : " << a.second << "\n";
    // }
    // cout << "------------------- answer\n";
    // for(auto a : answer){
    //     cout << a << "\n";
    // }

    return answer;
}