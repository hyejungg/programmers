#include <string>
#include <vector>
#include <queue>
using namespace std;

int ROW, COL;
vector<vector<bool>> v;

//지울 블럭 체크 ... 있으면 true, 없으면 false 반환
bool check(int ii, int jj, vector<string> board)
{
    int iter_x[3] = {1, 1, 0};
    int iter_y[3] = {0, 1, 1};
    char c = board[ii].at(jj);

    for (int i = 0; i < 3; i++)
    {
        int next_x = jj + iter_x[i];
        int next_y = ii + iter_y[i];
        if (next_x >= COL || next_y >= ROW ||
            c != board[next_y].at(next_x))
        {
            return false;
        }
    }

    v[ii][jj] = true;
    for (int i = 0; i < 3; i++)
    {
        int next_x = jj + iter_x[i];
        int next_y = ii + iter_y[i];
        v[next_y][next_x] = true;
    }
    return true;
}

vector<string> erase(vector<string> board)
{
    for (int i = 0; i < ROW; i++)
    {
        queue<char> q;
        for (int j = ROW - 1; j >= 0; j--)
        {
            if (v[j][i]) //지워야할블럭
                continue;
            q.push(board[j][i]);
        }
        for (int j = ROW - 1; j >= 0; j--)
        {
            if (q.empty())
                board[j][i] = 'x';
            else
            {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board)
{
    ROW = m;
    COL = n;
    int answer = 0;
    bool flag = false;
    while (!flag)
    {
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (board[i][j] == 'x')
                    continue;
                if (check(i, j, board))
                    flag = true;
            }
        }
        if (!flag)
            break;
        board = erase(board);
        flag = false;
    }

    //answer 계산
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == 'x')
                answer++;
        }
    }

    return answer;
}