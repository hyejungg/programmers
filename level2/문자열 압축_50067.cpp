#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 100000; //세팅

    if (s.size() == 1)
        return 1; //예외처리

    //i단위로 문자열을 자름
    for (int i = 1; i < s.size(); i++)
    {
        //cnt는 중복 횟수, result는 문자열 길이
        int cnt = 1, result = 0;
        string before = "", current = "";

        //j는 잘린 단위의 시작 인덱스
        for (int j = 0; j < s.size(); j += i)
        {
            current = s.substr(j, i);

            //이전 문자열과 비교
            if (before == current)
                cnt++;
            else
            {
                //길이만 구하면 되니까 잘린 현재 문자열.size()를 reuslt에 더해줌
                if (cnt == 1)
                    result += current.size();
                else
                    result += (to_string(cnt).size() + current.size());
                cnt = 1; //다시 초기화
            }
            before = current; //이전값 현재로 초기화
        }
        //마지막 반복자
        if (cnt != 1)
            result += to_string(cnt).size();

        if (answer > result)
            answer = result;
    }
    return answer;
}