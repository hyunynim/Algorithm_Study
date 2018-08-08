#include<cstdio>

int main() {
	int n;
	char msg[123];
	scanf("%d %s", &n, msg);

	int pos = 0;
	int l = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (msg[i] == 'P') {
			++l;
			if (pos == 1) {
				ans = 6;
			}
		}
		else {
			++pos;
			if (pos == 2)
				break;
		}
	}
	if (pos < 2)
		printf("0");
	else {
		if (ans == 6)
			printf("6");
		else {
			if (l % 2)
				printf("1");
			else
				printf("5");
		}
	}
}