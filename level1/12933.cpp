#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n)
{
    string temp = to_string(n);
    sort(temp.begin(), temp.end(), greater<char>()); //내림차순으로 temp 정렬
    return stoll(temp);                              //string을 long 타입으로 형변환
}