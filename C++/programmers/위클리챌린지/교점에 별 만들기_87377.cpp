#include <string>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_~ 기호상수 사용
using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    // long long minX = 0, minY = 0, maxX = 0, maxY = 0; 실패
    //그림 그리기 위해 x에 대한 min, max
    long long minX = LLONG_MAX, minY = LLONG_MAX;
    long long maxX = LLONG_MIN, maxY = LLONG_MIN;

    vector<pair<long long, long long>> maps;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            //교점 구하기
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            long long xNumerator = (B * F) - (E * D);
            long long yNumerator = (E * C) - (A * F);
            long long denominator = (A * D) - (B * C);

            if (denominator == 0) //분모가 0이면 구할 수 X
                continue;

            if (xNumerator % denominator || yNumerator % denominator) //정수인 것만 교점으로 이용할꺼니까
                continue;

            long long x = xNumerator / denominator;
            long long y = yNumerator / denominator;

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);

            maps.push_back({x, y}); //별 찍기 위해 x, y 따로 저장
        }
    }
    string row = string(maxX - minX + 1, '.');   //인자길이만큼의 '.' 문자열 생성
    vector<string> answer(maxY - minY + 1, row); // init

    for (pair<long long, long long> map : maps)
    {
        answer[abs(map.second - maxY)][abs(map.first - minX)] = '*'; //별로 치환
    }
    return answer;
}
// https://jaimemin.tistory.com/1995