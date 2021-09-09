#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers)
{
    int answer = 45; // 0 ~ 9까지 더한 값

    for (auto n : numbers)
        answer -= n;

    return answer > 0 ? answer : 0;
}