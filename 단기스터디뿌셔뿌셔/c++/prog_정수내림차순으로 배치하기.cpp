#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string nStr = to_string(n);
    sort(nStr.begin(), nStr.end(), greater<int>());
    return stol(nStr);
}