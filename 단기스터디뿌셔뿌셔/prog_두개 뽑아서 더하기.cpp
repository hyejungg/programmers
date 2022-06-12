#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> numList;
    sort(numbers.begin(), numbers.end());
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){ 
            int num = numbers[i] + numbers[j];
            numList.insert(num);
        }
    }
    vector<int> answer(numList.begin(), numList.end());
    return answer;
}