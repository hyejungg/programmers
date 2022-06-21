#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    return s.size() % 2 != 0 ? s.substr((s.size() / 2), 1) : s.substr((s.size() / 2) - 1, 2);
}

#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    if(s.size() % 2 != 0)
        answer = s[(s.size() / 2)];
    else
        answer = s.substr((s.size() / 2) - 1, 2);
    return answer;
}