#include<cstdio>

int main() {
	int n;
	char msg[100];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		fgets(msg, 99, stdin);
		printf("%d. %s", i+1, msg);
	}
}