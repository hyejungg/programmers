#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    // (3*2) * (2*2) = (3*2)

    for (int i = 0; i < arr1.size(); i++)
    { //arr1의 row
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++)
        { //arr2의 col
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++)
            { //행렬의 곱
                sum += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum); //(x,y)위치의 값 넣기
        }
        answer.push_back(temp);
    }

    return answer;
}