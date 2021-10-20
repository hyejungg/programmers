#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(string a, string b){
    // 두 문자열중에 먼저 N번째 문자를 사전순으로 비교하고 같을 경우, 문자열 자체를 비교
    return a[N] == b[N] ? a < b : a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    //내가 원하는 방법으로 정렬
    N = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}