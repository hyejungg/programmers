#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	int n, m, ipt; //문서의 개수, 궁금한 문서 위치, 중요도
	for (int i = 0; i < testCase; ++i)
	{
		int cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq; // 우선순위 큐 (deafult : 내림차순)
		for (int j = 0; j < n; ++j)
		{
			cin >> ipt;
			q.push({j, ipt});
			pq.push(ipt);
		}
		while (!q.empty())
		{
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value)
			{
				pq.pop();
				cnt++;
				if (index == m)
				{
					cout << cnt << endl;
					break;
				}
			}
			else
				q.push({index, value});
		}
	}
}