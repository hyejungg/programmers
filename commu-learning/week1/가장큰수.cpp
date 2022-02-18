#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b){
    //앞뒤로 이은 값 > 뒤앞으로 이은 값보다 큰 순으로(ture) 정렬
    return (a + b > b + a) ? true : false; 
}

string solution(vector<int> numbers) {
    string answer = "";
    
    //sort로 숫자끼리 비교를 위해 string 배열에 담아 (10 같은 숫자 -> 1개로 처리)
    vector<string> numList;
    for(auto n : numbers)
        numList.push_back(to_string(n));
    
    sort(numList.begin(), numList.end(), cmp);
    
    for(auto n : numList){
        cout << n << "\n";
        answer += n;
    }
    
    return answer;
}