#include <iostream>
#include <stack>

using namespace std;

int main() {
	long long a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	stack <int> tmp1, tmp2;
	while (b > 0) {
		tmp1.push(b % 10);
		b /= 10;
	}

	while (d > 0) {
		tmp2.push(d % 10);
		d /= 10;
	}
	while (tmp1.size()) {
		a = a * 10 + tmp1.top();
		tmp1.pop();
	}
	while (tmp2.size()) {
		c = c * 10 + tmp2.top();
		tmp2.pop();
	}
	printf("%lld", a + c);
}