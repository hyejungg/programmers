#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{

    int answer = 1;
    int size = s.size();
    while (size >= 2)
    {
        for (int i = 0; i <= s.size() - size; i++)
        {
            int left = i, right = size + i - 1;
            bool check = true; //팰린드롬 체크
            while (left <= right)
            {
                if (s[left] != s[right])
                {
                    check = false;
                    break;
                }
                left++;
                right--;
            }
            if (check)
                return size;
        }
        size--;
    }

    return answer;
}