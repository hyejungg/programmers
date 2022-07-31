#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int col, row;
vector<vector<string>> r;
vector<int> v;
vector<vector<int>> key;

void go(int index, int cnt)
{

    //원하는 개수를 다 뽑았으면
    if (cnt == 0)
    {

        //최소성 확인 - 후보키에 이미 같은 조합이 있는지 확인
        if (!key.empty())
        {
            for (int i = 0; i < key.size(); i++)
            {

                bool isMinimal = false;

                //후보키 안에 모두 같은 속성이 있을 시 minimal X
                //-> 후보키 안에 하나라도 다른 속성이 있으면 OK
                for (int j = 0; j < key[i].size(); j++)
                {
                    bool alreadyIn = false;
                    for (int k = 0; k < v.size(); k++)
                    {
                        if (key[i][j] == v[k])
                        {
                            alreadyIn = true;
                        }
                    }
                    if (!alreadyIn)
                    {
                        isMinimal = true;
                    }
                }

                if (!isMinimal)
                {
                    return;
                }
            }
        }

        //유일성 확인 - 모든 튜플을 식별할 수 있는지 확인
        vector<string> cmp;
        bool isUnique = true;

        //후보키로 문자열 만들기
        for (int i = 0; i < row; i++)
        {
            string s = "";
            for (int j = 0; j < v.size(); j++)
            {
                s += r[i][v[j]];
            }
            cmp.push_back(s);
        }

        sort(cmp.begin(), cmp.end());

        //문자열 중 같은 것이 있다면 -> 식별X
        for (int i = 0; i < row - 1; i++)
        {
            if (cmp[i] == cmp[i + 1])
            {
                isUnique = false;
            }
        }

        //최종적으로 가능한 후보키 저장
        if (isUnique)
        {
            key.push_back(v);
        }

        return;
    }

    //갯수만큼 저장
    for (int i = index; i < col; i++)
    {
        v.push_back(i);
        go(i + 1, cnt - 1);
        v.pop_back();
    }

    return;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;

    //전역변수에 값 저장
    r = relation;
    col = relation[0].size();
    row = relation.size();

    //1,2.. 개씩 뽑기
    for (int i = 1; i <= col; i++)
    {
        go(0, i);
    }

    //결과 저장
    answer = key.size();

    return answer;
}

//더 나은 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// 조합 경우의 수
/*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 이름, 학번
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
     */

//최소성 확인
bool minimal(vector<int> &vec, int now)
{
    //ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인
    for (int i = 0; i < vec.size(); i++)
        if ((vec[i] & now) == vec[i]) //같다면(&) 최소성 만족 X
            return false;
    return true;
}
int solution(vector<vector<string>> relation)
{
    int n = relation.size();           //ROWSIZE
    int m = relation[0].size();        //COLSIZE
    vector<int> ans;                   //후보키(유일성, 최소성 만족)
    for (int i = 1; i < (1 << m); i++) //i < (1 << m) : i가 1
    {
        set<string> s; //유일성 체크용 set
        for (int j = 0; j < n; j++)
        {
            string now = "";
            for (int k = 0; k < m; k++)
            {
                if (i & (1 << k)) // 선택된 컬럼과 일치한다면
                    now += relation[j][k];
            }
            s.insert(now);
        }

        //유일성(s.size() == ROWSIZE)과 최소성(minimal) 체크
        if (s.size() == n && minimal(ans, i))
            ans.push_back(i);
    }
    return ans.size();
}