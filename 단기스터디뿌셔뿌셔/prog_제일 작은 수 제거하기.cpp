#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr);
    
    int minValue = *min_element(arr.begin(), arr.end());
    int position = find(answer.begin(), answer.end(), minValue) - answer.begin();
    answer.erase(answer.begin() + position);
    
    return answer.empty() ? vector<int>(1, -1) : answer;
}