#include <string>
#include <vector>
#include <iostream>
using namespace std;

//vector가 아닌 배열로 생성할 경우 용량이 2배 .....

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> numbers(n, vector<int>(n, 0)); //값을 채워 넣을 직각 삼각형
    int num = 1, x = -1, y = 0, p = n;

    //배열 채우기
    for (int i = 0; i < n; i++)
    {
        for (int j = p; j >= 1; j--)
        {
            if (i % 3 == 0)
            { //좌하향
                numbers[++x][y] = num;
            }
            else if (i % 3 == 1)
            { //우측
                numbers[x][++y] = num;
            }
            else if (i % 3 == 2)
            { //우상향
                numbers[--x][--y] = num;
            }
            num++;
        }
        p--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            answer.push_back(numbers[i][j]);
    }

    return answer;
}