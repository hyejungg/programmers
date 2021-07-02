#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n)
{
    int num = bitset<20>(n).count(); //n의 비트 중 1의 개수
    int answer = n + 1;
    while (bitset<20>(answer).count() != num)
        answer++;

    return answer;
}