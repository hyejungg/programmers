#include <string>
#include <vector>

using namespace std;

typedef struct Loc
{
    int x;
    int y;
} Loc;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    //왼손, 오른손 좌표 저장
    Loc left, right;
    left.x = 0;
    left.y = 3;
    right.x = 2;
    right.y = 3;

    //numbers 배열 탐색하며 손가락 사용 여부 확인
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 3 == 1)
        { // 1,4,7인 경우
            answer += "L";
            //현재 위치 저장
            left.x = 0;
            if (numbers[i] == 1)
                left.y = 0;
            else if (numbers[i] == 4)
                left.y = 1;
            else if (numbers[i] == 7)
                left.y = 2;
        }
        else if (numbers[i] % 3 == 0 && numbers[i] != 0)
        { //3,6,9인 경우
            answer += "R";
            right.x = 2;
            if (numbers[i] == 3)
                right.y = 0;
            else if (numbers[i] == 6)
                right.y = 1;
            else if (numbers[i] == 9)
                right.y = 2;
        }
        else
        { //2,5,8,0인 경우
            //각 키패드의 위치 초기화
            Loc temp;
            temp.x = 1;
            if (numbers[i] == 2)
                temp.y = 0;
            else if (numbers[i] == 5)
                temp.y = 1;
            else if (numbers[i] == 8)
                temp.y = 2;
            else if (numbers[i] == 0)
                temp.y = 3;

            //두 엄지 손가락 위치와 현재 키패드 위치의 거리 계산
            int leftDiff = abs(temp.y - left.y) + abs(temp.x - left.x);
            int rightDiff = abs(temp.y - right.y) + abs(temp.x - right.x);

            if (leftDiff < rightDiff)
            { //왼손 엄지가 더 가까운 경우
                answer += "L";
                left.x = temp.x;
                left.y = temp.y;
            }
            else if (leftDiff > rightDiff)
            { //오른손 엄지가 더 가까운 경우
                answer += "R";
                right.x = temp.x;
                right.y = temp.y;
            }
            else
            { //거리가 같은 경우
                if (hand == "left")
                {
                    answer += "L";
                    left.x = temp.x;
                    left.y = temp.y;
                }
                else
                {
                    answer += "R";
                    right.x = temp.x;
                    right.y = temp.y;
                }
            }
        }
    }
    return answer;
}