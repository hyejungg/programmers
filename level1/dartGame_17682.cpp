#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 1. dartResult를 잘라서 점수|보너스|옵션으로 나눈다.
// 2. 나눈 값을 로직에 따라 점수 계산을 한다.
// 2-1. 영역별 점수 계산을 한다.
// 2-2. 옵션으로 얻은 점수 게산을 한다.
// 3. 각 단계에서 구한 점수를 합한다.

int solution(string dartResult)
{
    int answer = 0;

    vector<int> score;
    string number_str = "";

    for (int i = 0; i < dartResult.length(); ++i)
    {
        if (dartResult[i] != 'S' && dartResult[i] != 'D' && dartResult[i] != 'T' && dartResult[i] != '*' && dartResult[i] != '#')
        {                                //숫자인 경우
            number_str += dartResult[i]; //10이어도 그냥 이어 붙이도록
        }
        else
        {
            int current_number = atoi(number_str.c_str()); //숫자로 바꿔줌
            if (dartResult[i] == 'S')
            {
                score.push_back(current_number);
                number_str = ""; //다시 초기화
            }
            else if (dartResult[i] == 'D')
            {
                current_number = pow(current_number, 2);
                score.push_back(current_number);
                number_str = "";
            }
            else if (dartResult[i] == 'T')
            {
                current_number = pow(current_number, 3);
                score.push_back(current_number);
                number_str = "";
            }
            else if (dartResult[i] == '*')
            { //스타상
                score[score.size() - 1] *= 2;
                if (score.size() > 1)
                { //이전에 *이 존재한다면 앞에 껏도 2배로
                    score[score.size() - 2] *= 2;
                }
            }
            else if (dartResult[i] == '#')
            { //아차상
                score[score.size() - 1] *= -1;
            }
        }
    }

    for (int i = 0; i < score.size(); i++)
        answer += score[i];

    return answer;
}
//더 나은 대안
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
    stringstream ss(dartResult);

    int sum[3] = {0, 0, 0}; //각 횟수별로 저장
    int options[3] = {1, 1, 1};
    for (int i = 0; i < 3; i++)
    {
        int score;
        char bonus;
        char option;

        ss >> score; //ss의 값 중 숫자(int)를 score에 저장

        // .get()은 int로 형변환하지만 char 변수에 담아서 원 값을 저장
        bonus = ss.get();  //ss의 값 중 문자 1개를 가져와 bonus에 저장 // S, D, T
        option = ss.get(); //ss의 값 중 문자 1개를 가져와 option에 저장 // *, #

        // .unget()은 마지막에 읽은 글자를 buffer에 담음
        if (option != '*' && option != '#')
        {
            ss.unget(); //EOF를 담겠지?
        }

        switch (bonus)
        {
        case 'S':
            sum[i] += pow(score, 1);
            // sum[i] += score;
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option)
        {
        case '*':
            //횟수가 1차례 이상이고, 이전 값에 *가 존재한다면
            if (i > 0 && options[i - 1])
                options[i - 1] *= 2; //이전 값도 2배
            options[i] *= 2;         //이번 값도 2배
            break;
        case '#':
            options[i] = -options[i];
            //options[i] *= -1;
            break;
        default:
            break;
        }
    }

    //각 회차별(0,1,2) 점수 값을 더함
    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}