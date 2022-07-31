//이해하기 좋은 코드
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    unordered_set <int> s[8]; // s[i] : i + 1 개로 만들 수 있는 수 모음
    int answer = -1;
    int num = 0;

    for (int i = 0; i < 8;i++)
    {
        num = num * 10 + N;
        s[i].insert(num);
    }

    for (int i = 1;i < 8;i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int a : s[j])
            {
                for (int b: s[i - j - 1])
                {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b)
                        s[i].insert(a / b);
                }
            }
        }
    }
    for (int i = 0;i < 8;i++)
    {
        if (s[i].find(number) != s[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

//깔끔한 코드법
#include <string>
#include <vector>
#include <set>

#define MIN 8
using namespace std;

set<int>nums[MIN + 1];
int solution(int N, int number) {
	nums[1].insert(N);
	for (int i = 2; i <= MIN; i++) {
		for (int num : nums[i - 1]) {
			vector<int>next_values = { num * 10 + N ,num + N,num - N,num * N};
			if (N > 0)
				next_values.push_back(num / N);
			if (num > 0)
				next_values.push_back(N / num);

			for (int k = 0; k < next_values.size(); k++) {
				nums[i].insert(next_values[k]);
			}
		}
	}

	for (int i = 1; i <= MIN; i++) {
		for (int num : nums[i]) {
			if (num == number)
				return i;
		}
	}
	return -1;
}