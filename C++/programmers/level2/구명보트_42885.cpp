#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int sum_weight = 0;

    sort(people.begin(), people.end()); //오름차순으로 정렬 (뒤에부터 빼려고)

    int idx = 0;
    while (people.size() > idx)
    {
        int back = people.back();
        people.pop_back();
        if (people[idx] + back <= limit)
        { //가장 적은 값 + 가장 큰 값 <= limit 라면
            answer++;
            idx++; //둘 다 태웠다는 뜻 idx로 조정
        }
        else
            answer++;
    }

    return answer;
}