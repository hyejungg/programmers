using namespace std;

long long solution(int w, int h)
{
    long long answer = 1;
    int gcd = 0;
    long long all = (long long)w * (long long)h;
    int start = w < h ? w : h; //더 작은 값을 start로 두고 최대공약수를 구함
    for (int i = start; i > 0; i--)
    {
        if ((w % i == 0) && (h % i) == 0)
        {
            gcd = i;
            break;
        }
    }

    answer = all - gcd * ((w / gcd) + (h / gcd) - 1);

    return answer;
}