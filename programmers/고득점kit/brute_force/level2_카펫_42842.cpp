#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    int len = brown / 2 + 2; //가장 맨 윗줄을 구하기 위해

    int w = len - 3; //len을 이용하여 가장 맨 윗줄을 구함
    int h = 3;       //높이는 최소 3이상 (가운데에 yellow가 있어야 하니까)

    while (w >= h)
    {
        if ((w * h) == (brown + yellow))
            break;
        w--;
        h++;
    }

    return vector<int>{w, h};
}