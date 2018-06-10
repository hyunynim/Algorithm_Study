#include<cstdio>
#include<string.h>

int main() {
	int n;
	char msg[123];
	while (1) {
		scanf("%d", &n);
		getchar();
		if (n) {
			int j = 0;
			for (int i = 0; i < n; ++i) {
				fgets(msg, 101, stdin);
				while (msg[j] != '\0' && msg[j] != '\n' && msg[j] != ' ' && strlen(msg) > j )
					++j;
			}
			printf("%d\n", j+1);
		}
		else {
			return 0;
		}
	}
}