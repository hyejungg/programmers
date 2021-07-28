#include <string>
#include <map>
using namespace std;

int solution(string dirs)
{
    int answer = 0;
    map<pair<pair<int, int>, pair<int, int>>, bool> visit; //first : {(출발좌표), (도착좌표)}, second : 방문여부(true/false)

    int cur_x = 5;
    int cur_y = 5; //시작 위치

    for (int i = 0; i < dirs.size(); i++)
    {
        //시작 위치 세팅
        int start_x = cur_x;
        int start_y = cur_y;

        if (dirs[i] == 'U')
        { //상
            if (cur_x - 1 < 0)
                continue;
            cur_x--;
        }
        else if (dirs[i] == 'D')
        { //하
            if (cur_x + 1 > 10)
                continue;
            cur_x++;
        }
        else if (dirs[i] == 'L')
        { //좌
            if (cur_y - 1 < 0)
                continue;
            cur_y--;
        }
        else if (dirs[i] == 'R')
        { //우
            if (cur_y + 1 > 10)
                continue;
            cur_y++;
        }

        if (visit[{{start_x, start_y}, {cur_x, cur_y}}])
            continue;

        //방문체크
        visit[{{start_x, start_y}, {cur_x, cur_y}}] = true;
        visit[{{cur_x, cur_y}, {start_x, start_y}}] = true;
        answer++;
    }

    return answer;
}