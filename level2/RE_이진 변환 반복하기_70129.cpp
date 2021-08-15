#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer(2, 0); //초기화 //안하면 오류 발생
    int binaryCnt = 0;        //이진 변환 횟수
    int zeroCnt = 0;          //0의 개수

    while (s != "1")
    {
        binaryCnt++;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zeroCnt++;
            else
                temp += "1"; //1로만 이루어진 문자열 생성
        }
        int num = temp.size(); //1로만 이루어진 문자열의 길이 반환
        s = "";
        while (num != 0)
        { //num을 이진 값으로 변환
            s += to_string(num % 2);
            num /= 2;
        }
    }
    answer[0] = binaryCnt;
    answer[1] = zeroCnt;

    return answer;
}