#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            answer[i]++;
            if (prices[i] > prices[j])
                break;
        }
    }

    return answer;
}
//스택, 큐를 이용한 방법
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size()); //가격이 떨어지지 않는 기간
    stack<int> s;                      //시간을 저장

    //prices 배열을 돌며 탐색
    for (int i = 0; i < prices.size(); i++)
    {
        //s가 비지않고, 가장 마지막 원소 top이 현재 주식 가격(prices[i])보다 크다면
        // (주식가격을 유지하지 못함)
        //answer에 (현재 주식 시간(i) - s의 마지막원소)를 저장
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i); //현재 시간을 저장
    }

    //가장 마지막 원소 top이 현재 주식 가격보다 작아서 for문에서 while을 돌지 못한 경우
    //prices의 가장 큰 시간(n-1) - s에서 가장 마지막 원소(s.top())
    while (!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}