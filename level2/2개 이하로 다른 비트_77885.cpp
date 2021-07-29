#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0) //짝수라면, 최하위 비트가 0
            answer.push_back(numbers[i] + 1);
        else
        { //홀수라면, 최하위 비트가 1
            long long bit = 1;
            while (true)
            {
                if ((numbers[i] & bit) == 0)
                    break;
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    return answer;
}
//비트 연산을 사용한 문제 풀이
#include <vector>
using namespace std;
vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (long long number : numbers)
    {
        long long bit = 1;
        while ((number & bit) > 0)
            bit <<= 1;
        answer.push_back(number + bit - (bit >> 1));
    }
    return answer;
}
