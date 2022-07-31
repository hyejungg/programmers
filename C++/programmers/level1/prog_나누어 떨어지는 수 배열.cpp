#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }
    return answer.size() > 0 ? answer : vector<int>{-1};
}