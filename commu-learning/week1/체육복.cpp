#include <string>
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