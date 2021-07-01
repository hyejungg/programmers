#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    //1,2번 인덱스 값을 더한 값이 2,1번 인덱스를 더한 값보다 크다면 true : false
    //true인 경우 정렬
    return (a + b > b + a) ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_str;
    if(numbers.size() < 1) return "0";
    
    //배열을 돌며 각 수 탐색
    for(int i = 0; i < numbers.size(); i++){
        num_str.push_back(to_string(numbers[i]));
    }
    sort(num_str.begin(), num_str.end(), cmp); // 6, 2, 10이런 식으로 정렬되도록
    
    if(num_str[0] == "0") return "0"; //가장 큰 수는 0
    
    //배열의 값으로 answer 완성
    for(auto s : num_str)
        answer += s;
    return answer;
}