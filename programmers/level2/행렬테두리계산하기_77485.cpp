#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> v(rows + 1, vector<int>(columns + 1)); //초기화해줘야 오류 X

    // rows x columns 짜리 배열 초기화
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            v[i][j] = ((i - 1) * columns + j);

    //행만큼 반복
    for (auto q : queries)
    {
        int x1 = q[0], y1 = q[1];
        int x2 = q[2], y2 = q[3];
        int min_value = 10001;

        int start = v[x1][y1]; //가장 맨 값 저장

        // 1. 맨 위 오른쪽으로(ㅡ)
        for (int i = x1; i < x2; i++)
        {
            v[i][y1] = v[i + 1][y1];
            min_value = min(min_value, v[i][y1]);
        }

        // 2. 맨 오른쪽 아래로(ㅣ)
        for (int i = y1; i < y2; i++)
        {
            v[x2][i] = v[x2][i + 1];
            min_value = min(min_value, v[x2][i]);
        }

        // 3. 맨 아래 왼쪽으로(ㅡ)
        for (int i = x2; i > x1; i--)
        {
            v[i][y2] = v[i - 1][y2];
            min_value = min(min_value, v[i][y2]);
        }

        // 4. 맨 왼쪽 위로(ㅣ)
        for (int i = y2; i > y1 + 1; i--)
        {
            v[x1][i] = v[x1][i - 1];
            min_value = min(min_value, v[x1][i]);
        }
        // 회전한 값들 중 가장 작은 수를 구해야 하므로 처음 값도 고려
        v[x1][y1 + 1] = start;
        min_value = min(min_value, v[x1][y1 + 1]);
        answer.push_back(min_value);
    }

    return answer;
}