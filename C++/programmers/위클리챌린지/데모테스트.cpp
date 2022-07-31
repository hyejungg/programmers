#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<vector<int>> v)
{
    //     vector<int> ans;
    //     map<int, int> m1; //왼쪽
    //     map<int, int> m2; //오른쪽 좌표

    //     //init
    //     for(auto a : v){
    //         m1[a[0]]++;
    //         m2[a[1]]++;
    //     }

    //     for(auto m : m1){
    //         if(m.second == 1)
    //             ans.push_back(m.first);
    //     }
    //     for(auto m : m2){
    //         if(m.second == 1)
    //             ans.push_back(m.first);
    //     }
    // xor 연산(^ : 두 수가 같으면 같은 값을, 다르면 다른값을 반환) 이용
    vector<int> ans(2, 0);

    ans[0] = v[0][0] ^ v[1][0] ^ v[2][0];
    ans[1] = v[0][1] ^ v[1][1] ^ v[2][1];

    return ans;
}