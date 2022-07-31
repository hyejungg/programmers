#include <string>
#include <vector>
using namespace std;

// 2차원 벡터 문제

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    for (int row = 0; row < arr1.size(); row++)
    {
        vector<int> temp;
        for (int col = 0; col < arr1[0].size(); col++)
        {
            temp.push_back(arr1[row][col] + arr2[row][col]);
        }
        answer.push_back(temp);
    }
    return answer;
}