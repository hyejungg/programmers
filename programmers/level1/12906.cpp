#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int current = arr[0];
    answer.push_back(current); //맨 처음 원소 넣어주기

    for (int i = 1; i < arr.size(); i++)
    { // 1번째부터 탐색
        if (current != arr[i])
        {
            answer.push_back(arr[i]); //다른 원소 값 넣어주기
            current = arr[i];         //current값 변경
        }
    }

    return answer;
}
//더 나은 대안
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;
    return answer;
}