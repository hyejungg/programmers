#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++)
    {
        if (signs[i] == true)
        {
            answer += absolutes[i];
        }
        else
        {
            int temp = absolutes[i] * -1; //음수로 변환
            answer += temp;
        }
    }
    return answer;
}