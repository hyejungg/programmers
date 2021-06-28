#include <string>
#include <vector>
using namespace std;

// 비트 연산 문제

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n, ""); //초기화 안하면 오류 발생 (Error:signal: illegal instruction (core dumped))

    //arr1, arr2를 loop를 돌려 벽인지, 공백인지 확인
    for (int i = 0; i < n; i++)
    {
        int temp = arr1[i] | arr2[i]; //row별로 비트 연산한 값을 temp에 담음

        for (int j = n - 1; j >= 0; j--) //temp의 각 요소가 0인지, 1인지
        {
            if ((temp & (1 << j)) != 0)
                // answer.push_back("#"); //Actual values differ from expected values
                answer[i].append("#");
            else
                answer[i].append(" ");
        }
    }
    return answer;
}