#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{

    int answer = 1;
    int size = s.size();
    while (size >= 2) // size가 2개 이상인 경우에만 동작
    {
        for (int i = 0; i <= s.size() - size; i++)
        {
            int left = i, right = size + i - 1; //이진탐색을 위해 left, right
            bool check = true;                  //팰린드롬 체크
            while (left <= right)
            {
                if (s[left] != s[right])
                {
                    check = false;
                    break;
                }
                //팰린드롬이라면, 위치를 옮겨가며 최대 팰린드롬 길이를 구하도록 left, right 조정
                left++;
                right--;
            }
            if (check)
                return size;
        }
        size--; //팰린드롬이 아니라면 size를 줄여 탐색
    }

    return answer;
}