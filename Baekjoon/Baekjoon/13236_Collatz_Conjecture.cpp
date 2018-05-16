#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while(1) {
		printf("%d ", n);
		if (n == 1)
			break;
		else if (n % 2 == 0)
			n /= 2;
		else {
			n *= 3;
			++n;
		}
	}
}