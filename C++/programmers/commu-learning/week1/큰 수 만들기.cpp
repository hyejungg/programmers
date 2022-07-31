#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
    string answer = "";

    //k만큼 뺀 수만 출력
    int idx = -1; //0번째 인덱스부터 검사하기 위함
    for (int i = 0; i < number.size() - k; i++)
    {
        char maxValue = ' ';
        for (int j = idx + 1; j <= k + i; j++)
        {
            if (maxValue < number[j])
            {
                maxValue = number[j]; //갱신
                idx = j;
            }
        }
        answer += maxValue;
    }
    return answer;
}
// 다른 풀이
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
    string s = ""; //큰 수가 될 수 있는 수가 늘어진 문자열
    for(int i = 0; i < number.length(); i++){
        // s가 비지 않았고
        // s의 가장 끝자리 수가 number의 현재 수보다 작고
        // k가 0이 아니라면
        while(!s.empty() && s.back() < number[i] && k > 0){
            s.pop_back();
            k--;
        }
        if(k == 0){
            s += number.substr(i, number.length() - 1);
            break;
        }
        s.push_back(number[i]);
    }
    return s.substr(0, s.length() - k); // k만큼 뺀게 없다면
}