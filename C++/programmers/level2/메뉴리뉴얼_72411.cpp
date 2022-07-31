#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m; //first : 가능한 조합(AB, AC, AD ..), second : 조합의 개수  // [AB : 2]

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void findAll(string order, int size, string s, int idx)
{
    //종료조건
    if (s.size() == size)
    {
        map<string, int>::iterator iter;

        iter = m.find(s);

        if (iter != m.end()) //이미 존재한다면
            iter->second++;
        else
            m.insert({s, 1});

        return;
    }

    //idx부터 한글자씩 잘라서 조합 생성
    //재귀
    for (int i = idx; i < order.size(); i++)
        findAll(order, size, s + order[i], i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    //코스 별로
    for (int i = 0; i < course.size(); i++)
    {
        m.clear(); //초기화

        for (int j = 0; j < orders.size(); j++)
        {
            //한 줄을 오름차순으로 정렬 //CAB -> ABC로
            sort(orders[j].begin(), orders[j].end());

            //조합 만들기
            if (course[i] <= orders[j].size())
                findAll(orders[j], course[i], "", 0);
        }
        //map -> v로 옮김 (정렬을 위해서)
        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp); //개수가 큰 순으로 정렬

        if (!v.empty())
        {
            int max = v[0].second;

            //한 사람당 2개 이상 주문해야하므로
            if (max >= 2)
            {
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i].second == max)
                        answer.push_back(v[i].first);
                    else
                        break;
                }
            }
        }
    }
    //오름차순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}