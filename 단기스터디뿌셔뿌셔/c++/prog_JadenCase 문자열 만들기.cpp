#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower); //소문자로 모두 변경
    
    string answer = "";
    answer += toupper(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == ' '){
            answer += toupper(s[i]);
        }else{
            answer += tolower(s[i]);
        }
    }
    return answer;
}