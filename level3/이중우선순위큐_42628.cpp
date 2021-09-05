#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2, 0); //2개짜리 배열. 0으로 초기화

    priority_queue<int, vector<int>> pq_desc;              //내림차순 정렬
    priority_queue<int, vector<int>, greater<int>> pq_asc; //오름차순 정렬 (greater 사용 시 구현체 사용 꼭)
    int cnt = 0;                                           //q.size();

    for (auto oper : operations)
    {
        if (oper.at(0) == 'I')
        {                                   //삽입 명령 수행
            string number = oper.substr(2); //2번 idx부터 끝까지 숫자
            pq_desc.push(stoi(number));
            pq_asc.push(stoi(number));
            cnt++;
        }
        else
        { //삭제 명령 수행
            if (cnt == 0)
                continue; //큐가 비었는데 삭제 요청

            string number = oper.substr(2); //2번 idx부터 끝까지 숫자
            if (number == "1")              //최대값 삭제
                pq_desc.pop();
            else if (number == "-1") //최소값 삭제
                pq_asc.pop();

            cnt--; //q에서 삭제가 일어났으니
        }

        //만약 큐가 0이라면 desc, asc 모두 다 지워줌(균일하게 지워주기 위함)
        if (cnt == 0)
        {
            while (!pq_desc.empty())
                pq_desc.pop();
            while (!pq_asc.empty())
                pq_asc.pop();
        }
    }

    if (cnt)
    {                              //q에 값이 존재한다면
        answer[0] = pq_desc.top(); //최대값
        answer[1] = pq_asc.top();  //최소값
    }

    return answer;
}