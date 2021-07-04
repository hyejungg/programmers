#include <string>
#include <vector>
using namespace std;

vector<int> answer(2, 0);

void divide_conquer(vector<vector<int>> &a, int x, int y, int s)
{
    if (s < 1)
        return; //예외처리

    int num = a[x][y];

    for (int i = x; i < x + s; i++)
    {
        for (int j = y; j < y + s; j++)
        {
            if (a[i][j] != num)
            {
                divide_conquer(a, x, y, s / 2);
                divide_conquer(a, x + s / 2, y, s / 2);
                divide_conquer(a, x, y + s / 2, s / 2);
                divide_conquer(a, x + s / 2, y + s / 2, s / 2);
                return;
            }
        }
    }
    answer[num]++;
}

vector<int> solution(vector<vector<int>> arr)
{
    int size = (int)arr.size();
    divide_conquer(arr, 0, 0, size);
    return answer;
}