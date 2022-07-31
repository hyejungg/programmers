#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    //일반 map(O(log N)) 사용 시 시간초과 발생 -> 해시map 사용으로 변경 unordered_map(O(1))
    unordered_map<string, int> hash_book; // first : phone_number, second : count

    //일단 담아
    for (auto &p : phone_book)
    {
        string str = "";
        for (int i = 0; i < p.size(); i++)
        {
            str += p[i];
            hash_book[str]++; //한 글자씩 count ++ ex. 119라면 1, 11, 119
        }
    }

    //중복해서 들어가 있는지 검사
    for (auto &p : phone_book)
        if (hash_book[p] > 1)
            return false;

    return true;
}

//그냥 map 사용도 ok
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;

bool solution(vector<string> phone_book)
{
    for (auto pb : phone_book)
    {
        string str = "";
        for (int i = 0; i < pb.size(); i++)
        {
            str += pb[i];
            m[str]++;
        }
    }

    for (auto pb : phone_book) // map으로 탐색하면 실패
    {
        if (m[pb] > 1)
            return false;
    }
    return true;
}