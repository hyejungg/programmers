#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    //정렬 안하면 실패
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int match = A.size();
    int idx = 0;
    for (int i = 0; i < match; i++)
    {
        if (B[i] > A[idx])
        {
            answer++;
            idx++;
        }
    }
    return answer;
}