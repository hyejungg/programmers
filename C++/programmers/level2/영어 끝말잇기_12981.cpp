#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2, 0);
    map<string, int> m;
    m[words[0]]++; //미리 초기화

    for (int i = 1; i < words.size(); i++)
    {
        m[words[i]]++; //초기화

        //탈락자
        if (m[words[i]] > 1 || //같은 단어를 가진 사람 존재
            words[i - 1].back() != words[i].front())
        { //이전 끝 글자 != 이번 앞 첫글자
            int num = i % n + 1;
            int round = i / n + 1;
            answer[0] = num;
            answer[1] = round;
            break; //탈락자가 발생하면 바로 종료
        }
    }
    return answer;
}