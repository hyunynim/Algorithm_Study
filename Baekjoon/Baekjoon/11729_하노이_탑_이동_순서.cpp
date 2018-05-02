#include<cstdio>
#include<algorithm>
#include<deque>

int NextTarget(int from, int target) {
	int calc = from * 10 + target;
	switch (calc) {
	case 12:
		return 3;
	case 13:
		return 2;
	case 21:
		return 3;
	case 23:
		return 1;
	case 31:
		return 2;
	case 32:
		return 1;
	}
}
int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

using namespace std;
deque<int> stick[4];

int k = 0;
void hanoi(int num, int from, int target) {
	if (stick[from].front() != num) {
		hanoi(num - 1, from, NextTarget(from, target));
		printf("%d %d\n", from, target);
		stick[target].push_front(stick[from].front());
		stick[from].pop_front();
		hanoi(num - 1, NextTarget(from, target), target);
	}
	else {
		printf("%d %d\n", from, target);
		stick[target].push_front(stick[from].front());
		stick[from].pop_front();
	}
	++k;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", pow(2, n) - 1);
	for (int i = 1; i <= n; ++i)
		stick[1].push_back(i);
	hanoi(n, 1, 3);
}

/*comment*/
//num, target을 출력하는게 아니라 from, target을 출력하는거임 ㅡㅡ;