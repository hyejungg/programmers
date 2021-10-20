#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int depth)
{
    if (depth == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    dfs(numbers, target, sum + numbers[depth], depth + 1); //numbers의 값을 더해서 타겟을 구하는 경우
    dfs(numbers, target, sum - numbers[depth], depth + 1); //numbers의 값을 빼서 타겟을 구하는 경우
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, 0, 0); //dfs 호출

    return answer;
}