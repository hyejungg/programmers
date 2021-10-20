#include <string>
#include <vector>
using namespace std;

//상 하 우 좌로 탐색
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isVisit[5][5];
bool flag;

void checkMHTDist(vector<string> &p, int x, int y, int deep)
{
    for (int i = 0; i < 4; i++)
    {
        if (deep == 2 || flag)
            return; //맨해튼 거리가 2이상이면 볼 필요도 없음

        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5)
        { //새 x,y가 범위 내에 있고
            if (!isVisit[next_x][next_y] && p[next_x][next_y] != 'X')
            { //아직 방문하지 않았으며 X가 아닌 경우(P or O)
                if (p[next_x][next_y] == 'P')
                {
                    flag = true;
                    return;
                }
                else
                {
                    isVisit[next_x][next_y] = true;
                    checkMHTDist(p, next_x, next_y, deep + 1);
                }
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (auto &p : places)
    {
        //행별로 isVisit와 flag 다시 초기화
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                isVisit[i][j] = false;
            }
        }
        flag = false;

        //places 는 5x5
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (!isVisit[i][j] && p[i][j] == 'P')
                {
                    isVisit[i][j] = true;
                    checkMHTDist(p, i, j, 0);
                }
                if (flag)
                { //1명이라도 거리두기를 하지 않은 경우
                    answer.push_back(0);
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            answer.push_back(1);
    }

    return answer;
}

//더 나은 대안
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
"POOOP",
"OXXOX", 
"OPXPX",
"OOXOX",
"POXXP"
*/

bool is_valid_place(const vector<string> &place)
{
    constexpr size_t N = 5; //constexpr : 컴파일 타임에 상수를 확실히 사용. 컴파일 타임에 const는 초기화될 수도 있음

    vector<vector<bool>> is_in_use(
        N,
        vector<bool>(N, false)); //is_in_use를 bool 타입의 nxn 배열로 생성.

    //탐색에 사용될 위치 (우 좌 상 하)
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            if (place[i][j] == 'P')
            {
                for (size_t k = 0; k != 4; ++k)
                {
                    size_t moved_i = i + di[k];
                    size_t moved_j = j + dj[k];

                    if (moved_i >= N || moved_j >= N) //새 x, y가 범위 내에 존재하지 않다면
                        continue;

                    switch (place[moved_i][moved_j])
                    {
                    case 'P':
                        return false;
                    case 'O':
                        if (is_in_use[moved_i][moved_j])
                            return false;

                        is_in_use[moved_i][moved_j] = true;
                        break;
                    case 'X':
                        break;
                    }
                }
            }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer(5);
    //행 별로 거리두기 여부를 확인 후 결과를 answer에 저장
    for (size_t i = 0; i < 5; i++) //size_t는 이론상 가장 큰 사이즈를 담을 수 있는 unsigned 데이터 타입
        answer[i] = is_valid_place(places[i]);
    return answer;
}