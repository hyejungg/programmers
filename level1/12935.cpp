//혜정 풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int min_value = *min_element(arr.begin(), arr.end());

    // 가장 작은 수 값 찾기
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.size() == 1)
        {
            answer.push_back(-1);
            break;
        }
        if (arr[i] == min_value)
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}
// 더 나은 대안 (vector>헤더의 함수를 적극 활용한 버전)

#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return {-1};
    }
    arr.erase(std::min_element(arr.begin(), arr.end()));
    return arr;
}