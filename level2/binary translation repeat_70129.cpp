#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer(2, 0);
    int cnt = 0; //진법 계산 횟수 - answer에 들어감
    int sum = 0; //총 토탈 값 - answer에 들어감
    int zero_cnt = 0;

    while (s != "1")
    {
        cnt++;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zero_cnt++; //"0"은 오류남
            else
                temp += "1"; //1로만 이루어진 문자열 생성
        }
        int num = temp.size();
        s = ""; //s를 초기화
        while (num != 0)
        {
            s += to_string(num % 2); //s를 새로 생성한 num을 기반으로 갱신
            num /= 2;
        }
    }

    answer[0] = cnt;
    answer[1] = zero_cnt;
    return answer;
}