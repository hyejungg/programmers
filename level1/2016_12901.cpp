#include <string>
#include <vector>
using namespace std;

string solution(int a, int b)
{
    string answer = "";
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //윤년 고려(29일까지)
    //1월 1일이 금요일 -> 1번째 인덱스는 FRI
    string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    //a월 전까지의 일수들을 모두 더한 후
    int sum = b;
    for (int i = 0; i < a - 1; i++)
    {
        sum += month[i];
    }
    //7로 나눈 나머지 값은 n월 m일 즉, m이 나옴
    return day[sum % 7];
}