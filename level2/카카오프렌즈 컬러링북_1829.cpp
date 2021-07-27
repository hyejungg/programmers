// #include <vector>
// #include <algorithm>
// #include <queue>

// using namespace std;

// bool ch[101][101];
// int dy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// int bfs(int val, int x, int y, int m, int n, vector<vector<int>> picture)
// {
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     ch[x][y] = true;
//     int area = 1;
//     while (!q.empty())
//     {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dy[i][0];
//             int ny = y + dy[i][1];
//             if (nx < 0 || nx >= m || ny < 0 || ny >= n || ch[nx][ny] || picture[nx][ny] != val)
//                 continue;
//             q.push({nx, ny});
//             ch[nx][ny] = true;
//             area++;
//         }
//     }
//     return area;
// }

// // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// vector<int> solution(int m, int n, vector<vector<int>> picture)
// {
//     int number_of_area = 0;
//     int max_size_of_one_area = 0;
//     vector<int> answer(2);
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ch[i][j] = false;
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (!ch[i][j] && picture[i][j] > 0)
//             {
//                 int area = bfs(picture[i][j], i, j, m, n, picture);
//                 number_of_area++;
//                 max_size_of_one_area = max(max_size_of_one_area, area);
//             }
//         }
//     }

//     answer[0] = number_of_area;
//     answer[1] = max_size_of_one_area;
//     return answer;
// }
//내코드 -> segmentation fault 내일 다시 해보기....
#include <vector>
#include <queue> //bfs
using namespace std;

bool visit[101][101]; // = {false, }; //방문 여부  //**solution 밖에서 초기화 시 정확성 테스트 통과 불가
//좌 상 하 우
int row[4] = {-1, 0, 0, 1};
int col[4] = {0, 1, -1, 0};
int width;
int height;

// bool rangeCheck(int a, int b){
//     return (a >= width || a < 0 || b >= height || b < 0) ? false : true;
// }

int dfs(int x, int y, const vector<vector<int>> pic)
{
    int area = 1;
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int cx = x + row[i];
        int cy = y + col[i];

        if (cx < 0 || cx >= width || cy < 0 || cy >= height)
            continue;
        else
        {
            if (!visit[cx][cy] && pic[cx][cy] > 0)
            {
                area += dfs(cx, cy, pic); //재귀로 호출하여 area 값을 더해 최대 영역의 수를 구함
            }
        }
    }
    return area;
}

int bfs(int x, int y, const vector<vector<int>> pic)
{
    int color = pic[x][y]; //target

    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    int area = 1; //영역 내 블록 개수
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        //좌 상 하 우로 영역 탐색
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + row[i];
            int next_y = cur_y + col[i];

            //범위 체크
            if ((next_x >= width || next_x < 0 || next_y >= height || next_y < 0))
                continue; //함수로 빼니까 segmentation fault 발생.....
            else
            { //next_x, next_y가 범위 내에 있다면
                //아직 방문하지 않았고, 방문할 pic의 배열이 target과 같다면
                if (!visit[next_x][next_y] && pic[next_x][next_y] == color)
                {
                    visit[next_x][next_y] = true;
                    q.push({next_x, next_y});
                    area++;
                }
            }
        }
    }

    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;       //영역 수
    int max_size_of_one_area = 0; //가장 큰 영역의 사이즈

    vector<int> answer(2);

    //전역변수 초기화
    width = m;
    height = n;
    for (int i = 0; i <= width; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            visit[i][j] = false;
        }
    }

    //bfs 방식으로 배열을 돌며 영역 개수와 가장 큰 영역의 개수를 구하기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j] && picture[i][j] > 0)
            {
                //bfs
                int area = bfs(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max_size_of_one_area < area ? area : max_size_of_one_area;

                //dfs
                int area = dfs(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max_size_of_one_area < area ? area : max_size_of_one_area;
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}