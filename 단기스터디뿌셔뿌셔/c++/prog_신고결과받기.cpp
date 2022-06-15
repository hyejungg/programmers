#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> reportCnt; //유저, 신고당한 횟수
    map<string, set<string>> reportLog; //유저, 신고한 유저리스트
    
    for(auto& r : report){
        int blank = r.find(' ');
        string from = r.substr(0, blank);
        string to = r.substr(blank);
        
        //아직 from 유저가 to 유저를 신고한 적이 없다면
        if(reportLog[from].find(to) == reportLog[from].end()){
            ++reportCnt[to];
            reportLog[from].insert(to);
        }
    }
    
    for(auto& id : id_list){
        int mail = 0;
        
        for(auto& user : reportLog[id]){
            if(reportCnt[user] >= k) ++mail;
        }
        answer.push_back(mail);
    }
    
    return answer;
}