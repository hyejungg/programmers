#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int findNumIdx(string s) //숫자 시작 위치 반환
{
    int idx;
    for (idx = 0; idx < s.length(); idx++)
    {
        if (s[idx] >= '0' && s[idx] <= '9')
            break;
    }
    return idx;
}
int getNumber(string s)
{
    return stoi(s.substr(findNumIdx(s)));
}
string getHeader(string s)
{
    string head = s.substr(0, findNumIdx(s));
    
    //대소문자 모두 같은 순서로 취급하므로 소문자로 변경
    transform(head.begin(), head.end(), head.begin(), ::tolower);
    return head;
}

bool numComp(string a, string b) { return getNumber(a) < getNumber(b); }
bool headComp(string a, string b) { return getHeader(a).compare(getHeader(b)) < 0; }

vector<string> solution(vector<string> files)
{   
    stable_sort(files.begin(), files.end(), numComp); //숫자 기준 정렬
    stable_sort(files.begin(), files.end(), headComp); //head 기준 정렬

    return files;
}