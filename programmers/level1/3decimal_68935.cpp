#include <string>
#include <vector>
#include <iostream>
using namespace std;

int pow(int n)
{
    if (n == 0)
        return 1;
    else
        return 3 * pow(n - 1);
}

int solution(int n)
{
    int answer = 0;
    int temp = n;
    vector<int> tmp_ans;
    while (temp > 0)
    {
        tmp_ans.push_back(temp % 3); //나머지 // 0, 0, 2, 1
        temp /= 3;                   //몫
    }
    for (int i = 0; i < tmp_ans.size(); i++)
    {
        answer += tmp_ans[i] * pow(tmp_ans.size() - 1 - i);
        cout << answer << " ";
    }
    return answer;
}
//더 나은 대안
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<int> v;
    while (n > 0)
    {
        v.push_back(n % 3);
        n /= 3;
    }
    int k = 1;
    while (!v.empty())
    {
        answer += k * v.back();
        v.pop_back();
        k *= 3;
    }

    return answer;
}