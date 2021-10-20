#include <iostream>
using namespace std;

int main()
{
    int N, X, K;
    cin >> N >> X >> K; //N개의 컵, X번째의 공이 존재, K번 위치 변경
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == X)
        {
            X = b;
        }
        else if (b == X)
        {
            X = a;
        }
    }
    cout << X;
}