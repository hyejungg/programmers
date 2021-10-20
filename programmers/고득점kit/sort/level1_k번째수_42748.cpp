#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //배열 돌아
    for(int i = 0; i < commands.size(); i++){
        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int pick = commands[i][2] - 1;
        
        //temp 배열에 담아
        vector<int> temp;
        for(int i = start; i <= end; i++)
            temp.push_back(array[i]);
        
        sort(temp.begin(), temp.end()); //temp를 오름차순 정렬해
        answer.push_back(temp[pick]); //temp에서 pick값에 해당하는 값 answer에 넣어
    }
    return answer;
}