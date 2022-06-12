#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getRanks(int cnt){
    switch(cnt){
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int okCnt = 0;
    int minRank = 0, maxRank = 0;
    for(auto& win : win_nums){
        for(int i = 0; i < lottos.size(); i++){
            if(win == lottos[i])
                ++okCnt;
        }
    }
    
    int zeroCnt = 0;
    for(auto& lotto : lottos){
        if(lotto == 0)
            ++zeroCnt;
    }
    
    minRank = getRanks(okCnt);
    maxRank = getRanks(okCnt + zeroCnt);
    
    vector<int> answer = {maxRank, minRank};
    return answer;
}