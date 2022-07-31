#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    //주어진 문자열이 1개인 경우, 무조건 true
    if (phone_book.size() <= 1)
        return true;

    sort(phone_book.begin(), phone_book.end()); //사전순으로 정렬

    for (int i = 1; i < phone_book.size(); i++)
    {
        if (phone_book[i].find(phone_book[i - 1]) == 0) //이전 값과 비교
            return false;
    }
    return true;
}
//더 나은 대안 (hash문제. hash_map을 이용해야 함)
#include <string>
#include <vector>
#include <unordered_map> //hash_map 헤더파일

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    unordered_map<string, int> hash_map; //first: 번호, second: count?
    for (int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) //phone_book 인덱스에 들어있는 번호의 하나하나 검사 (ex. 119라면 1,1,9 개별 검사)
        {
            phone_number += phone_book[i][j];
            if (hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}
