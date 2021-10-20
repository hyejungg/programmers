#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return (a + b > b + a) ? true : false;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> num;

    for (int i = 0; i < numbers.size(); i++)
    {
        num.push_back(to_string(numbers[i]));
    }
    sort(num.begin(), num.end(), cmp);

    for (auto n : num)
        answer += n;

    return answer;
}

//이 방법으로 풀어내면 풀리긴 하나 시간초과 발생
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> num_str;

    //오름차순 정렬
    sort(numbers.begin(), numbers.end());

    //순열 생성
    do
    {
        string str = "";
        for (int i = 0; i < numbers.size(); i++)
            str += to_string(numbers[i]);
        num_str.push_back(str);
    } while (next_permutation(numbers.begin(), numbers.end())); //새 조합으로

    //오름차순으로 정렬
    sort(num_str.begin(), num_str.end());

    return num_str[num_str.size() - 1];
}