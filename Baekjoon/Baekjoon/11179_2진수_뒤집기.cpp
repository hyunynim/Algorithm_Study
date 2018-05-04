#include<cstdio>
#include<queue>

using namespace std;

int main() {
	int n;
	queue<int> bin;
	scanf("%d", &n);
	while (n > 0) {
		bin.push(n % 2);
		n /= 2;
	}
	while (bin.size()) {
		n = n * 2 + bin.front();
		bin.pop();
	}
	printf("%d", n);
}