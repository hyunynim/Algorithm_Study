#include<cstdio>
#include<string.h>

int main() {
	char msg[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		if ((msg[strlen(msg) - 1] - '0') % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");
	}
}