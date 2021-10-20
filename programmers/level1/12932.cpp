#include <string>
#include <vector>
using namespace std;
vector<int> solution(long long n)
{
    vector<int> answer;
    long long temp = n;
    //일의자리부터 배열 뒤집어 넣기
    while (temp != 0)
    {
        answer.push_back(temp % 10);
        temp /= 10;
    }
    return answer;
}