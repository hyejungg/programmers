#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int sum_weight = 0;

    sort(people.begin(), people.end()); //오름차순으로 정렬

    //50, 50, 70, 80
    int idx = 0;
    while (people.size() > idx)
    {
        int back = people.back(); //가장 큰 값
        people.pop_back();
        if (people[idx] + back <= limit)
        {
            answer++;
            idx++; //둘 다 태웠으니까 idx++해서 다음 친구 태워
        }
        else
        { //가장 큰 값 먼저 태워
            answer++;
        }
    }

    return answer;
}