#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int get = nums.size() / 2; //선택할 수 있는 폰켓몬의 개수
    set<int> s;                //n번 폰켓몬의 개수

    //배열을 돌면서 1,2,..,n번 폰켓몬의 개수를 구함
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    return (s.size() <= get) ? s.size() : get;
}