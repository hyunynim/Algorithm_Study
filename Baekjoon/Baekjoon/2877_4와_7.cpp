#include<cstdio>
#include<stack>

using namespace std;

int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	int n;
	int prec[30] = { 0, 2 };
	stack<int> res;
	for (int i = 2; i < 30; ++i) 
		prec[i] = prec[i - 1] + pow(2, i);
	scanf("%d", &n);
	int cnt = 0;
	--n;
	for (int i = 1; i < 30; ++i) {
		if (n < prec[i]) {
			cnt = i;
			break;
		}
	}
	int tmp = n - prec[cnt-1];
	while (tmp > 0) {
		res.push(tmp % 2 ? 7 : 4);
		tmp /= 2;
	}
	while (cnt != res.size()) {
		printf("4");
		cnt--;
	}
	while (res.size()) {
		printf("%d", res.top());
		res.pop();
	}
}