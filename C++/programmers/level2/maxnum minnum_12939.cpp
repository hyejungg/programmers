#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> v;
    istringstream ss(s);
    string strbuffer = "";
    while (getline(ss, strbuffer, ' '))
    { //공백을 기준으로 구분
        v.push_back(stoi(strbuffer));
    }
    sort(v.begin(), v.end());
    answer += to_string(v.front()); //최소값
    answer += " ";
    answer += to_string(v.back()); //최대값

    return answer;
}