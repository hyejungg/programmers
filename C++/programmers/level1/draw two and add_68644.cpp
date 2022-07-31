#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    //배열을 돌면서 서로 다른 인덱스의 값을 더해
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (i != j)
                answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end()); //오름차순으로 정렬 후
    //unique로 중복된 원소 앞으로 뺀 뒤 erase로 나머지(중복되지 않은 값) 삭제
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}
//대박 똑똑한 대안
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
 * set은 중복값을 저장하지 않는다는 점을 이용
 */

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    set<int> st;
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            st.insert(numbers[i] + numbers[j]);
        }
    }
    //assign() st의 begin() ~ end()까지의 원소들을 answer에 대입
    answer.assign(st.begin(), st.end());
    return answer;
}