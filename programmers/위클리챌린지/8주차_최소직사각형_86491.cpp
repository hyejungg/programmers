#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int FRONT = 0;
const int BACK = 1;

int solution(vector<vector<int>> sizes)
{
    vector<int> biggerValue;
    vector<int> smallerValue;

    for (auto s : sizes)
    {
        //[작은 값, 큰 값]으로 다시 자리 재배치
        if (s[FRONT] > s[BACK])
        {
            int temp = s[FRONT];
            s[FRONT] = s[BACK];
            s[BACK] = temp;
        }
        smallerValue.push_back(s[FRONT]);
        biggerValue.push_back(s[BACK]);
    }
    int minValue = *max_element(smallerValue.begin(), smallerValue.end());
    int maxValue = *max_element(biggerValue.begin(), biggerValue.end());

    return minValue * maxValue;
}