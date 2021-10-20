#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define CACHE_HIT 1;
#define CACHE_MISS 5;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<string> cache; //캐시 생성

    for (int i = 0; i < cities.size(); i++)
    { //도시 탐색
        string temp = cities[i];
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower); //소문자로 변환

        bool isValid = false;
        for (int j = 0; j < cache.size(); j++)
        { //캐시 탐색
            if (cache[j] == temp)
            { //캐시에 존재하는 경우
                isValid = true;
                answer += CACHE_HIT;
                cache.erase(cache.begin() + j);
                cache.push_back(temp);
                break;
            }
        }
        if (!isValid)
        { //캐시에 존재하지 않는 경우
            answer += CACHE_MISS;
            if (cacheSize != 0 && cache.size() >= cacheSize)
                cache.erase(cache.begin());
            if (cache.size() < cacheSize)
                cache.push_back(temp);
        }
    }
    return answer;
}