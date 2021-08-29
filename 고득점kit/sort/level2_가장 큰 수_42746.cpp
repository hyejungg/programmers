#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    //앞뒤로 더한게 뒤앞으로 더한 것보다 크다면
    return (a + b > b + a) ? true : false;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> temp;

    //배열의 값을 temp에 담아
    for (auto n : numbers)
        temp.push_back(to_string(n));

    //정렬
    sort(temp.begin(), temp.end(), cmp);

    if (temp[0] == "0")
        return "0"; //11번 TC 예외처리

    for (auto t : temp)
        answer += t;

    return answer;
}