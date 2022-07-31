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
    
    return answer[0] == '0' ? "0" : answer; //test case 11 예외처리
} 
// 다시 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b){
    // a+b했을 때, a를 앞서도록 할 때 true / b를 앞서도록 할 때 false
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 > s2; 
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto& n : numbers)
        ansewr += to_string(n);
    
    //test case 1번 예외
    return answer[0] == '0' ? "0" : answer;
} 