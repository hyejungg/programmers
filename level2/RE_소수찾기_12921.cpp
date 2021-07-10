#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false; //소수 아님
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    string s = numbers;                        //복사
    sort(s.begin(), s.end(), greater<char>()); //내림차순으로 정렬

    vector<bool> prime(stoi(s) + 1); //해당 숫자의 소수 여부를 체크
    for (auto i = 0; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }

    sort(numbers.begin(), numbers.end()); //정렬
    set<int> ans;                         //numbers 중 만들 수 있는 조합에서 소수인 경우 값 저장
    /*
     * @see : next_permutation(시작iter, 끝iter) : 해당 배열의 값으로 순열을 구함
              사용 전에 정렬을 해주어야 모든 순열을 뽑아낼 수 있음
              1 2 3 4 라는 값이 있다면 다음 순열은 1 2 4 3으로 바꾸고 true return. 
     */
    do
    {
        //만들 수 있는 소수 찾기
        for (int i = 1; i <= numbers.size(); i++)
        {
            string temp = numbers.substr(0, i); //numbers에서 1글자, 2글자 .. 씩 잘라서 검사
            int num_temp = stoi(temp);
            if (prime[num_temp])
            {
                ans.insert(num_temp);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return ans.size();
}