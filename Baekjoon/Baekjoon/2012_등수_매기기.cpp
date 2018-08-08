#include<queue>
#include<cstdio>
#include<functional>

using namespace std;

int Abs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n, tmp, cnt = 1;
	long long res = 0;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> score;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		score.push(tmp);
	}
	while (score.size()) {
		res += Abs(cnt - score.top());
		score.pop();
		++cnt;
	}
	printf("%lld", res);
}