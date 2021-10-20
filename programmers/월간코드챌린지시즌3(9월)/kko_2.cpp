#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//n진수로 변환
string calBit(int num, int k)
{
    string temp = "";
    while (num > 0)
    {
        temp += to_string((num % k));
        num /= k;
    }
    reverse(temp.begin(), temp.end()); //거꾸로 변환
    return temp;
}

bool isPrime(string str)
{
    //int로 변경
    long num = (str.size() > 1) ? stol(str) : str[0] - '0';

    if (num == 1)
        return false;
    if (num == 2)
    {
        return true;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    string temp = calBit(n, k);
    cout << temp;

    //0을 기준으로 앞, 뒤 문자가 prime인지 확인
    size_t pre = 0, cur;
    cur = temp.find('0'); //첫번째 0의 위치
    while (cur != string::npos)
    {
        string sub = temp.substr(pre, cur - pre);

        if (!sub.empty() && isPrime(sub))
            answer++;

        //다음 위치를 찾기 위해 idx 변경
        pre = cur + 1;
        cur = temp.find('0', pre);
    }
    //마지막 0 뒤 문자열 prime인지 확인
    string sub = temp.substr(pre, cur - pre);
    if (!sub.empty() && isPrime(sub))
        answer++;

    return (n == 1) ? 0 : answer;
}