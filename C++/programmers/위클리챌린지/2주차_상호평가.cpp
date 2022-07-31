#include <string>
#include <vector>
using namespace std;

//처음에 tc 10, 12, 16 실패 -> 유일한 값을 고려하지 않았음
//자기 자신으로 고려하도록 변경

string answer = "";
void getAnswer(int ans)
{
    if (ans >= 90)
        answer.push_back('A');
    else if (ans >= 80 && ans < 90)
        answer.push_back('B');
    else if (ans >= 70 && ans < 80)
        answer.push_back('C');
    else if (ans >= 50 && ans < 70)
        answer.push_back('D');
    else if (ans <= 50)
        answer.push_back('F');
}

string solution(vector<vector<int>> scores)
{
    int SIZE = scores.size(); //row.size == col.size 같은 배열

    for (int i = 0; i < SIZE; i++)
    {                                                   //col
        int max = 0, min = 10000, value = scores[i][i]; //최고점, 최저점, 자기자신
        int sum = 0;                                    //합 ... avg를 구하기 위해

        int c_max = 0, c_min = 0;
        for (int j = 0; j < SIZE; j++)
        { //row
            if (i == j)
                continue; //자기 자신 생략
            if (scores[j][i] >= max)
                max = scores[j][i];
            if (scores[j][i] <= min)
                min = scores[j][i];
            sum += scores[j][i]; //우선 모든 행의 값을 더해
        }
        if ((value > max) || (min > value))
        { //자기자신 값보다 크거나, 작은 경우 제외
            getAnswer(sum / (SIZE - 1));
            continue;
        }
        sum += value;
        getAnswer(sum / SIZE);
    }

    return answer;
}