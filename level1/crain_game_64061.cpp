#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> basket; //1x1짜리 배열

    int board_row_size = board.size();

    //moves에 있는 값들을 이용하여 board 내용 탐색
    for (int i = 0; i < moves.size(); i++)
    {
        int col = moves[i] - 1; //-1을 하는 이유는 실제 board의 index는 0부터 시작
        //board의 개별 row와 탐색
        for (int j = 0; j < board_row_size; j++)
        {
            if (board[j][i] == 0)
                continue;
            else
            {
                if (basket.empty())
                { //basket이 비어있다면 우선 값을 넣어줌
                    basket.push_back(board[j][col]);
                }
                else
                {
                    //basket의 가장 위의 값과 board에서 꺼내올 값이 같다면
                    if (basket[basket.size() - 1] == board[j][col])
                    {
                        basket.pop_back(); //basket에서 꺼냄으로써 pop을 2번 안해줘도 ok
                        answer += 2;       //개당 1개씩 터지니까 +2
                    }
                    else
                    {
                        basket.push_back(board[j][col]);
                    }
                }
                board[j][col] = 0; //moves로 지나온 친구는 0으로 초기화
                break;
            }
        }
    }
    return answer;
}