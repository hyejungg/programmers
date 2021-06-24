#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0; //카운트 수
    vector<int> temp = d;

    sort(temp.begin(), temp.end()); //d를 오름차순으로 정렬

    //d를 돌며 budget이 가능한 부서의 경우의 수를 구함
    for (int i = 0; i < temp.size(); i++)
    {
        if (budget - temp[i] >= 0)
        { //d배열 값들이 budget 보다 작다면
            budget -= temp[i];
            answer++; //카운트 증가
        }
        else //d배열 값들이 budget 보다 크다면 해당 x -> break;
            break;
    }
    return answer;
}