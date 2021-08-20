#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getNumberIdx(string s)
{
    int idx = 0;
    for (idx; idx < s.size(); idx++)
    {
        if (s[idx] >= '0' && s[idx] <= '9')
            return idx;
    }
}

int getNumber(string s)
{
    return stoi(s.substr(getNumberIdx(s)));
}

string getHeader(string s)
{
    string head = s.substr(0, getNumberIdx(s));

    transform(head.begin(), head.end(), head.begin(), ::tolower); //소문자로 변환

    return head;
}

bool cmpNum(string a, string b) { return getNumber(a) < getNumber(b); } //숫자는 오름차순
bool cmpHead(string a, string b)
{
    /* a.compare(b)
     * return 값이 0보다 작을 경우 : a > b
     * return 값이 0인 경우 : a == b
     * return 값이 0보다 클 경우 : a < b
     */
    return getHeader(a).compare(getHeader(b)) < 0;
}

vector<string> solution(vector<string> files)
{
    //stable_sort == 안정정렬
    stable_sort(files.begin(), files.end(), cmpNum);  //같은 문자의 경우 숫자 기준 정렬
    stable_sort(files.begin(), files.end(), cmpHead); //헤드 기준 정렬

    return files;
}

//정규표현식을 이용한 방법
#include <bits/stdc++.h> //regex도 써보려고 바꿈
using namespace std;

struct File
{
    string name;
    string header;
    string number;
    string tail;
};

bool cmp(const File &a, const File &b)
{ //숫자, 글 모두 오름차순 정렬
    if (a.header == b.header)
        return stoi(a.number) < stoi(b.number);
    else
        return a.header < b.header;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    regex re("(\\D+)(\\d+)(.*)"); //(header)(number)(tail) //+s는 1개 이상 //\를 반영하려면 \\(2개) 사용
    smatch matches;
    vector<File> file_list;
    for (auto file : files)
    {
        if (regex_match(file, matches, re))
        {
            string tmp = "";
            for (auto ch : matches[1].str())
                tmp += tolower(ch); //header
            file_list.push_back(File{matches[0].str(), tmp, matches[2].str(), matches[3].str()});
        }
    }

    stable_sort(file_list.begin(), file_list.end(), cmp);

    for (auto a : file_list)
        answer.push_back(a.name);

    return answer;
}