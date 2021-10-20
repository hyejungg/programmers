#include <string>
#include <vector>
using namespace std;

int solution(int ori_num)
{
    int answer = 0;          //result
    long long num = ori_num; //int -> long long 타입으로 변환하여 500인 경우 -1 반환

    while (num != 1)
    {
        if (num % 2 == 0)
        { //짝수라면
            num = num / 2;
            answer++;
        }
        else
        { //홀수라면
            num = (num * 3) + 1;
            answer++;
        }
    }
    return answer > 500 ? -1 : answer;
}