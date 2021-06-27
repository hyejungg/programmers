#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> temp;

    //command의 첫 번째 값으로 진행
    for (int row = 0; row < commands.size(); row++)
    {
        //init i,j,k //-1 하는 이유는 array의 인덱스는 0부터 시작~
        int i = commands[row][0] - 1;
        int j = commands[row][1] - 1;
        int k = commands[row][2] - 1;

        //array를 i,j에 따라 잘라 오름차순 정렬 후 k번째 값 구하기
        for (int aidx = i; aidx <= j; aidx++)
        {
            temp.push_back(array[aidx]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
        temp.clear(); //temp를 비움
    }

    return answer;
}
//더 나은 대안
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++)
    {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        //answer는 1차원 배열. k번째 == commands[i][0] + commands[i][2]-2로 표현
        answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);
    }

    return answer;
}