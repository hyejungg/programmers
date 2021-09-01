#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> check(n + 1, 1); //체육복 여부를 확인.

    //tc 13, 14번 예외처리
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());

    //초기화 체육복없는 애들, 있는 애들
    for (int i = 1; i <= n; i++)
    {
        for (auto l : lost)
            if (l == i)
                check[i]--;
        for (auto r : reserve)
            if (r == i)
                check[i]++;
    }

    //체육복 없는 애들은 있는 애들한테 빌려
    for (auto l : lost)
    {
        if (check[l] == 0)
        { //없다는 것
            if (check[l - 1] == 2)
            {
                check[l - 1]--;
                check[l] = 1;
            }
            else if (check[l + 1] == 2)
            {
                check[l + 1]--;
                check[l] = 1;
            }
        }
    }

    for (auto c : check)
        if (c > 0)
            answer++;

    return --answer; //check[0]은 없는 경우니까 빼기
}