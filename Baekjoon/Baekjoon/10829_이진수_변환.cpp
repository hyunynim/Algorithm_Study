#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	long long n;
	stack <int> bin;
	scanf("%lld", &n);
	while (n > 0) {
		bin.push(n % 2);
		n /= 2;
	}
	while (bin.size()) {
		printf("%d", bin.top());
		bin.pop();
	}
}