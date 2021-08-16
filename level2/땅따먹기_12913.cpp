//최고점을 구하는 문제 -> DP로 푸는게 적합하다고 함...

//시간 초과 발생
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0; //최고점
    int maxIdx = 0;

    // (n x 4) 배열
    for (int i = 0; i < land.size(); i++)
    {
        int max = land[i][0]; //각 행의 가장 첫 번째 값이 가장 큰 값
        for (int j = 1; j < 4; i++)
        {
            //이전 행과 같은 열이 아니면서 행에서 가장 큰 값이면
            if (max > land[i][j] && maxIdx != j)
            {
                max = land[i][j]; //max 값 갱신
                answer += max;    //max로 더해줌
            }
            maxIdx = j;
        }
    }

    return answer;
}

//정답 (각 행에서 가장 큰 값에 이전 행의 큰 값을 더해가는 방법)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이전 행에서 가장 큰 값 찾음
int getMax(vector<int> v, int idx)
{
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != idx)
            temp = max(temp, v[i]);
    }
    return temp;
}

int solution(vector<vector<int>> land)
{
    int answer = 0; //최고점

    // (n x 4) 배열
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            land[i][j] += getMax(land[i - 1], j); //이전 행에서 가장 큰 값을 현재 행에 더해줌
            answer = max(answer, land[i][j]);     //계속 갱신
        }
    }

    return answer;
}

// max_element() 함수를 이용한 방법 -> 이 방법 역시 각 행의 큰 값을 원래 배열에 갱신
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{

    for (int i = 0; i < land.size() - 1; i++)
    {
        land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] += max(land[i][1], max(land[i][0], land[i][3]));
        land[i + 1][3] += max(land[i][1], max(land[i][2], land[i][0]));
    }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}