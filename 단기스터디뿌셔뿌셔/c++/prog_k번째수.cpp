#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& command: commands){
        vector<int> arr;
        for(int i = command[0] - 1; i <= command[1] - 1; i++){
            arr.push_back(array[i]);
        }
        sort(arr.begin(), arr.end());
        answer.push_back(arr[command[2] - 1]);
    }
    return answer;
}