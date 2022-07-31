#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string calBit(int n)
{ //2진수, 16진수로 변환
    if (n <= 9)
        return to_string(n);
    switch (n)
    {
    case 10:
        return "A";
        break;
    case 11:
        return "B";
        break;
    case 12:
        return "C";
        break;
    case 13:
        return "D";
        break;
    case 14:
        return "E";
        break;
    case 15:
        return "F";
        break;
    }
    return "";
}

string solution(int n, int t, int m, int p)
{
    string str = "", ans = "";
    int cnt = 0;

    // 1) 전체 문자열 완성(str)
    while (1)
    {
        string temp = ""; //각 숫자별 진수 변환
        int num = cnt++;
        while (1)
        {
            temp += calBit(num % n);
            num /= n;
            if (num == 0)
                break;
        }
        reverse(temp.begin(), temp.end()); //진수 변환을 위한 순서 변경
        str += temp;
        if (str.size() > t * m)
            break; //m명인데 t만큼 말해야하니까 이 경기는 t * m 만큼 진행ㅇㅇ
    }

    // 2) 내 차례(p)일 때 말해야 하는(t) 문자열 구하기
    for (int i = 0; i < t; i++)
        ans += str[p - 1 + i * m];

    return ans;
}