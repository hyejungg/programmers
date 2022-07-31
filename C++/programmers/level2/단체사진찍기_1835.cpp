#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findCharIdx(vector<char> v, char c)
{
    int i;
    for (i = 0; v.size(); i++)
    {
        if (c == v[i])
            return i;
    }
    return -1;
}

void init(vector<char> &v)
{
    v.push_back('A');
    v.push_back('C');
    v.push_back('F');
    v.push_back('J');
    v.push_back('M');
    v.push_back('N');
    v.push_back('R');
    v.push_back('T');
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0; //경우의 수

    vector<char> list; //단체사진 찍을 사람들
    init(list);
    sort(list.begin(), list.end()); //오름차순 정렬

    //next_permutaion을 이용하여 경우의 수 조합을 구함
    do
    {
        bool flag = false;
        for (int i = 0; i < data.size(); i++)
        {
            //각 조건에 해당하는 사람(a, b)의 인덱스
            int a = findCharIdx(list, data[i][0]);
            int b = findCharIdx(list, data[i][2]);
            //간격
            int dist = (data[i][4] - '0') + 1; //숫자로 변환

            if (data[i][3] == '=')
            {
                flag = (abs(a - b) == dist) ? true : false;
            }
            else if (data[i][3] == '>')
            {
                flag = (abs(a - b) > dist) ? true : false;
            }
            else if (data[i][3] == '<')
            {
                flag = (abs(a - b) < dist) ? true : false;
            }

            if (!flag)
                break;
        }
        if (flag)
            answer++;
    } while (next_permutation(list.begin(), list.end()));

    return answer;
}