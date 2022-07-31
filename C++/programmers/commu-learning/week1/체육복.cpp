#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n + 1, 1);
    
    //체육복 있는 애, 없는 애 init
    for(int i = 1; i <= n; i++){
        for(auto l : lost){
            if(i == l)
                --clothes[i];
        }
        for(auto r : reserve){
            if(i == r)
                ++clothes[i];
        }
    }
    
    //체육복 없는 애들은 있는 애들한테 빌려
    for(auto l : lost){
        if(clothes[l] == 0){
            if(clothes[l - 1] == 2){
                clothes[l - 1] = 1;
                clothes[l] = 1;
            }else if(clothes[l + 1] == 2){
                clothes[l + 1] = 1;
                clothes[l] = 1;
            }
        }
    }
    
    //체육복을 있는 애들 확인
    for(auto c : clothes){
        if(c > 0)
            ++answer;
    }
    
    return --answer; //clothes의 크기가 n+1이니까
}

// 다른 방법
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 체육복을 잃어버린 애들의 집합 (순서 미지정)
    unordered_set<int> l(lost.begin(), lost.end()); // lost의 vector의 값으로 초기화
    set<int> r; // 체육복 여벌이 있는 애들의 집합
    unordered_set<int> inter; //l과 r의 교집합
    for(auto& x : reserve){
        if(l.find(x) == l.end()) //찾지 못한다면
            r.insert(x);
        else //찾았다면
            inter.insert(x);
    }
    for(auto& x : inter){
        l.erase(x);
    }
    for(auto& x : r){
        if(l.find(x - 1) != l.end()) //찾지 못한다면
            l.erase(x - 1); //빌려준 것
        else if(l.find(x + 1) != l.end())
            l.erase(x + 1);
    }
    return n - l.size(); 
}