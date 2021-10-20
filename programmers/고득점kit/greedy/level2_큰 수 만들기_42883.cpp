#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
    string answer = "";

    //k만큼 뺀 수만 출력
    int idx = -1; //0번째 인덱스부터 검사하기 위함
    for (int i = 0; i < number.size() - k; i++)
    {
        char maxValue = ' ';
        for (int j = idx + 1; j <= k + i; j++)
        {
            if (maxValue < number[j])
            {
                maxValue = number[j]; //갱신
                idx = j;
            }
        }
        answer += maxValue;
    }
    return answer;
}