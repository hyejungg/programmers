#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int sum = 0;

    //A배열 오름차순, B배열 내림차순으로 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < A.size(); i++)
    {
        int num = A[i] * B[i];
        sum += num;
    }

    return sum;
}