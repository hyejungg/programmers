#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n, ""); //n개 짜리 백터를 ""로 초기화

    for (int i = 0; i < n; i++)
    {
        int bit = arr1[i] | arr2[i]; //row별로 비트 계산
        for (int j = n - 1; j >= 0; j--)
        {
            if (bit & (1 << j))
            { //최하위 비트부터 탐색(1 << j)
                //append()는 string의 함수
                answer[i].append("#");
            }
            else
            {
                answer[i].append(" ");
            }
        }
    }

    return answer;
}