#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

bool isPrime(int n)
{
    //1보다 크면서 1과 자기자신만 약수를 갖는 수 == 소수
    if (n == 1 || n == 0)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) //소수가 아님
            return false;
    }
    return true;
}

int solution(string numbers)
{
    set<int> ans;                         //만들 수 있는 소수
    sort(numbers.begin(), numbers.end()); //오름차순으로 정렬

    //numbers를 돌며 순열을 생성하여 소수 확인
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            string temp = numbers.substr(0, i);

            if (isPrime(stoi(temp)))
                ans.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return ans.size();
}