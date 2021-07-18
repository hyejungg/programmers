#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int n = name.size();

    //상 하 조이스틱 : 알파벳 변경 (최소 이동 횟수)
    for (auto a : name)
    {
        answer += min(a - 'A', 'Z' - a + 1); //Z로 이동 후 고를 경우 Z로 바꿀(+1)
    }

    //좌 우 조이스틱 : 커서 변경(최소 이동 횟수)
    int left_min = n - 1;
    for (int i = 0; i < n; i++)
    {
        //'A'가 아닌 문자는 좌우 이동
        if (name[i] != 'A')
        {
            //다음 'A'가 아닌 인덱스 구하기
            int next_idx = i + 1;
            while (next_idx < n && name[next_idx] == 'A')
            {
                next_idx++;
            }
            // i위치에서 총 왼쪽 이동 횟수 구하기
            int left_move = i * 2 + n - next_idx;

            left_min = min(left_min, left_move);
        }
    }
    return answer += left_min;
}