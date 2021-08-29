#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), greater<int>()); //내림차순으로 정렬

    //예외처리
    if (citations[0] == 0)
        return 0;

    //h번 이하로 인용되었다면 h가 최대
    for (int i = 0; i < citations.size(); i++)
        if (citations[i] < (i + 1))
            return i;

    return citations.size();
}