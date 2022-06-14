#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCount = 0, yCount = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            ++pCount;
        else if(s[i] == 'y' || s[i] == 'Y')
            ++yCount;
    }

    return (pCount == yCount);
}