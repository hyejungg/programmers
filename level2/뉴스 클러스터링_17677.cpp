#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void split(string str, vector<string> &v)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        string temp = str.substr(i, 2); //2개씩 잘라
        //두 글자가 모두 문자인 경우에만 v에 추가
        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z')
            v.push_back(temp);
    }
}

int solution(string str1, string str2)
{
    int gyo = 0, hab = 0;
    double jacade = 0; //J(A, B)는 소수 값

    //집합 a, b //2글자씩 잘라서 보관
    vector<string> a;
    vector<string> b;

    //str1과 str2를 모두 소문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    split(str1, a); // str1 2개씩 잘라 집합 a 생성
    split(str2, b); // str2 2개씩 잘라 집합 b 생성

    //2개 집합 모두 빈 값 비교할 게 없으므로 -> 65536 return //testcase5
    if (a.empty() && b.empty())
        return 65536;

    //합집합과 교집합을 구한다.
    hab = a.size() + b.size();

    if (a.size() > b.size())
    {
        for (auto iter : b)
        {
            auto find_str = find(a.begin(), a.end(), iter); //a집합에서 iter와 같은 문자열을 반환
            if (find_str != a.end())
            { //b집합에서 찾았다면
                gyo++;
                a.erase(find_str);
            }
        }
    }
    else
    {
        for (auto iter : a)
        {
            auto find_str = find(b.begin(), b.end(), iter); //b집합에서 iter와 같은 문자열을 반환
            if (find_str != b.end())
            { //a집합에서 찾았다면
                gyo++;
                b.erase(find_str);
            }
        }
    }

    hab -= gyo;

    if (hab == 0)
        return 65536; //합집합이 0이라면 나눌 수 없으므로
    else
        jacade = (double)gyo / (double)hab;

    return jacade * 65536;
}
//맵으로 풀이 ...... 충격적....
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2)
{
    unordered_map<string, int> hash1;
    unordered_map<string, int> hash2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            hash1[str1.substr(i, 2)]++;

    for (int i = 0; i < str2.size() - 1; i++)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            hash2[str2.substr(i, 2)]++;

    int intersection_count = 0;
    int union_count = 0;

    for (auto &p : hash1)
        intersection_count += min(p.second, hash2[p.first]);

    for (auto &p : hash1)
        hash2[p.first] = max(hash2[p.first], p.second);

    for (auto &p : hash2)
        union_count += p.second;

    if (union_count == 0 && intersection_count == 0)
        return 65536;
    else
        return (double)intersection_count / union_count * 65536;
}