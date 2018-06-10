#include<cstdio>
#include<deque>

using namespace std;

bool isPel(int num) {
	deque<int> seq;
	while (num > 0) {
		seq.push_back(num % 10);
		num /= 10;
	}

	while (seq.size()) {
		if (seq.front() == seq.back()) {
			seq.pop_back();
			if (seq.empty())
				return 1;
			seq.pop_front();
		}
		else
			return 0;
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		int num;
		scanf("%d", &num);
		int res = num;
		int tmp = 0;
		while (num > 0) {
			tmp = tmp * 10 + num % 10;
			num /= 10;
		}
		res += tmp;
		if (isPel(res))
			printf("YES\n");
		else
			printf("NO\n");
	}
}