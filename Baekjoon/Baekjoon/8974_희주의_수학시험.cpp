#include<cstdio>

int main() {
	int a, b;
	int arr[123456] = { 0 };
	scanf("%d %d", &a, &b);
	int res = 0, cnt = 0;
	for (int i = 1; i < 300; ++i) {
		for (int j = 0; j < i; ++j) {
			arr[cnt++] = i;
		}
	}
	for (int i = a - 1; i < b; ++i)
		res += arr[i];
	printf("%d", res);
}