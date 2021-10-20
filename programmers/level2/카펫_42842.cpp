#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (int height = 3;; height++)
    {                                          //높이는 최소 3이상
        int width = (brown + yellow) / height; //가로의 길이는 두 카펫의 합의 height로 나눈 값
        if (width >= height && ((width - 2) * (height - 2) == yellow))
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}

//더 나은 대안
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red)
{

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while (w >= h) //기본 조건
    {
        if (w * h == (brown + red))
            break;

        w--;
        h++;
    }

    return vector<int>{w, h}; //백터 생성과 동시에 초기화한 값을 return
}