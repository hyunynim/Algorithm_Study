#include <iostream>

long long int num[101] = { 0, 1, 1, 1, 2 ,2, 3, 4, 5, 7, 9, 12, 16 };

long long int calc(int n) {
	if (num[n] == 0)
		num[n] = calc(n - 1) + calc(n - 5);
	return num[n];
}

int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", calc(n));
	}
	return 0;
}