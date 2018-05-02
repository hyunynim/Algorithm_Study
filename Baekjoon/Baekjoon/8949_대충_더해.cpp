#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int a, b;
	stack <int> num;
	scanf("%d %d", &a, &b);
	while (a > 0 || b > 0) {
		num.push(a % 10 + b % 10);
		a /= 10;
		b /= 10;
	}
	while (num.size()) {
		printf("%d", num.top());
		num.pop();
	}
}