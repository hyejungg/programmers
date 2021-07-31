#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 10000; //answer는 갱신할꺼라서 큰 값으로 초기화

    if (s.size() == 1)
        return 1; //예외처리

    // i : 문자열을 자룰 단위야
    for (int i = 1; i < s.size(); i++)
    {
        int cnt = 1;                      //중복횟수
        int result = 0;                   //return 될 압축한 문자열의 길이(size)
        string before = "", current = ""; //before는 이전 문자열, current는 현재 문자열

        // j : 잘린 문자열. j ~ i인덱스까지 잘라서 비교 탐색
        for (int j = 0; j < s.size(); j += i)
        {
            current = s.substr(j, i);

            // 두 문자열이 중복된다면, 압축해야함
            if (before == current)
                cnt++;
            else
            { //중복이 아니라면,
                if (cnt > 1)
                    result += to_string(cnt).size();
                else
                    result += (to_string(cnt).size() + current.size());
                cnt = 1; //다시 0으로 초기화
            }
            before = current; //현재 문자열은 반복문이 종료되면, 이전 문자열이 됨
        }

        //마지막 문자열이 이전 문자열과 같은 경우엔 cnt가 증가하여 1이 아니겠지?
        if (cnt != 1)
            result += to_string(cnt).size();

        if (answer > result)
            answer = result;
    }

    return answer;
}
/*
 * 처음에 시간 초과가 발생했는데 그 이유는 i를 0으로 시작으로 두어서 주의하자
*/