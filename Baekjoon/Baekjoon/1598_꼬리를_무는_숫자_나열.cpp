#include<cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	--a;
	--b;
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a % 4 == b % 4) {
		printf("%d", (b - a) / 4);
		return 0;
	}
	if(a % 4 > b % 4){
		printf("%d", (b - a) / 4 + 1 + (a%4 - b%4));
		return 0;
	}
	else {
		printf("%d", (b - a) / 4 + (b % 4 - a % 4));
	}
}
