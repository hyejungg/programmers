#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string temp[3] = {"4", "1", "2"}; //"412"[a]이렇게 해서 인덱스 접근도 가능...
    int idx = 0;
    while(n != 0){
        int idx = n % 3;
        answer = temp[idx] + answer; 
        if (!idx) //0이 아니라면
            n = n / 3 - 1;
        else
            n = n/3;
    }
    return answer;
}