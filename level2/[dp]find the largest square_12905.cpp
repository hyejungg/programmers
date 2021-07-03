//그냥 풀면 시간초과 발생하여 테스트도 못봄 ㅎㅎ...

//동적 계획법 이용
/*
네 점 중 오른쪽 아래 점을 기준으로 
왼쪽, 위쪽, 왼쪽 위 대각선의 수가 1이상 이면 정사각형 조건이 성립
*/
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    // int answer = 0; //실패 발생
    int answer = board[0][0];
    int row = board.size();
    int col = board[0].size();

    //정사각형 기준 오른쪽 맨 아래점부터 1인지 검사
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (board[i][j] == 1)
            {
                //위, 옆, 위대각선이 1의 값의 최소값을 [i][j] + 1한 값을 담음
                //+1은 (여기까지 정사각형 가능하다는 표시)
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);     //왼쪽, 위쪽
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1; //대각선
                answer = max(answer, board[i][j]);                       //정사각형의 변수 값
            }
        }
    }
    return answer * answer;
}
