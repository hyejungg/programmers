//실패(런타임 에러)
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// vector<int> solution(int n, long long k)
// {
//     vector<int> answer;

//     // n명의 사람에 맞는 사람 리스트
//     vector<int> list;
//     int num = 1;
//     for (int i = 0; i < n; i++)
//     {
//         list.push_back(num++);
//     }
//     int cnt = 0;
//     do
//     {
//         if (cnt == k)
//         {
//             for (int i = 0; i < list.size(); i++)
//             {
//                 answer.push_back(list[i]);
//             }
//             break;
//         }
//         cnt++;

//     } while (next_permutation(list.begin(), list.end()));

//     return answer;
// }
//다시
#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long factor[21] = {
    1,
};

vector<int> solution(int n, long long k)
{
    vector<int> answer, num;

    for (int i = 1; i <= n; i++)
    {
        factor[i] = factor[i - 1] * i;
        num.push_back(i); //시작 인덱스 저장
    }
    k--; //인덱스 번호 맞추기 위함(-1)
    while (n > 0)
    {
        int idx = k / factor[n - 1]; // k번째 순열의 시작 idx 찾기
        answer.push_back(num[idx]);
        num.erase(num.begin() + idx); // idx 찾았으니 삭제 후 다른 값 탐색
        k %= factor[n - 1];
        n--;
    }
    return answer;
}