#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// h회 이상 인용된 논문이 h개인지 찾는 최대값 문제

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>()); //내림차순으로 정렬
    if (citations[0] == 0)
        return 0; //가장 큰 값이 0이라면 h-index는 0

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= (i))
            answer++; //i는 인용횟수로 두고 비교
        else
            break;
    }

    return answer;
}