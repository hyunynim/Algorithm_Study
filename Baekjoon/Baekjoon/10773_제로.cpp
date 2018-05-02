#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	stack <int> num;
	int tmp;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &tmp);
		if (tmp == 0)
			num.pop();
		else
			num.push(tmp);
	}

	long long res = 0;
	while (num.size()) {
		res += num.top();
		num.pop();
	}
	printf("%lld", res);
}