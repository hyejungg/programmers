#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> getPrime(int n)
{
    vector<int> primes;

    //n의 약수를 구해 vector에 넣음
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            primes.push_back(i);

    return primes;
}

int solution(int left, int right)
{
    int answer = 0;
    vector<int> temp;
    map<int, int> ans; //first : 숫자, second : 개수를 담을 ans

    //map에 숫자(first), 숫자의 소수(second)를 넣음
    for (int i = left; i <= right; i++)
    {
        temp = getPrime(i);
        ans.insert({i, temp.size()});
    }

    for (auto &i : ans)
    {
        if (i.second % 2 == 0) //짝수라면
            answer += i.first;
        else //홀수라면
            answer -= i.first;
    }

    return answer;
}