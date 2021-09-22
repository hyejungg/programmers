#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
    int n = enter.size(); //오늘 입실, 퇴실한 사람들 수
    vector<int> answer(n, 0);
    deque<int> inQ, outQ;

    //배열을 돌면서 입, 퇴실 여부 체크
    for (int i = 0; i < n; i++)
    {
        int in = enter[i];  //방 들어온 사람
        int out = leave[i]; //방 나가는 사람

        //deque에 넣어
        inQ.push_back(in);
        outQ.push_back(out);

        int qSize = inQ.size();

        for (int i = qSize - 1; i >= 0; i--)
        {
            int temp = inQ[i]; //뒤에서부터 검사

            //outQ[0]은 나가야하는 사람
            if (!outQ.empty() && temp == outQ[0])
            {
                outQ.pop_front();
                inQ[i] = -1; //나갔다는 표시

                for (int j = 0; j < inQ.size(); j++)
                {
                    //배열에 있는 사람 수 == 현재 나가는 사람의 만난 수
                    if (inQ[j] == -1)
                        continue;
                    answer[temp - 1]++;
                }

                for (int j = 0; j < inQ.size(); j++)
                {
                    //현재 나간 사람 만났으니 배열에 있는 사람들 다 +1 해줌
                    if (inQ[j] == -1)
                        continue;
                    answer[inQ[j] - 1]++;
                }
                i = qSize - 1; //큐에 남은 사람들 재확인을 위해 i 재정의
            }
        }
    }

    return answer;
}

//더 나은 풀이
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
    int n = enter.size(); //나가고 들어온 사람들의 수
    vector<int> ret(n);   //return 할 정답(answer) 배열

    set<int> hold; //나간 사람, 들어온 사람 확인을 위해 중복 제거 set 이용?
    for (int i = 0, j = 0; i < n; ++i)
    {
        //enter[i] - 1 인 이유는 enter와 leave 배열의 사람들은 1부터 시작
        ret[enter[i] - 1] += hold.size();
        for (int it : hold)
            ret[it - 1]++;

        hold.insert(enter[i]);
        while (j < n && hold.find(leave[j]) != hold.end())
            hold.erase(leave[j++]);
    }

    return ret;
}