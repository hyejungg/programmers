#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string nStr = to_string(n);
    for(auto& n : nStr){
        answer += n - '0';
    }
    return answer;
}