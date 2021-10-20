#include <vector>
#include <queue>
using namespace std;

bool visit[101][101] = {
    false,
};
//상 하 좌 우
int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

int solution(vector<vector<int>> maps)
{
    int width = maps.size();     //n
    int height = maps[0].size(); //m

    queue<pair<pair<int, int>, int>> q; //first.first : x, first.second : y, second : distance
    //출발 (0, 0) 시작거리는 1
    q.push({{0, 0}, 1});
    visit[0][0] = true;

    while (!q.empty())
    {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_dist = q.front().second;
        q.pop();

        //현재 x, y가 maps의 마지막이라면
        if (cur_x == width - 1 && cur_y == height - 1)
            return cur_dist;

        // 상 하 좌 우로 탐색
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + row[i];
            int next_y = cur_y + col[i];
            int next_dist = cur_dist + 1;

            //범위에 해당 안된다면
            if (next_x < 0 || next_x >= width || next_y < 0 || next_y >= height)
                continue;

            //아직 방문하지 않았고, 벽이 아닌 길이라면
            if (!visit[next_x][next_y] && maps[next_x][next_y] == 1)
            {
                q.push({{next_x, next_y}, next_dist});
                visit[next_x][next_y] = true;
            }
        }
    }

    return -1; //범위 내에서 거리를 구하지 못했다면
}
