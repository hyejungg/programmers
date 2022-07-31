#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> noCompletionMap;
    
    for(auto p : participant){
        noCompletionMap[p]++;
    }
    
    for(auto c : completion){
        noCompletionMap[c]--;
    }
    
    for(auto m : noCompletionMap){
        if(m.second > 0)
            return m.first;
    }
}