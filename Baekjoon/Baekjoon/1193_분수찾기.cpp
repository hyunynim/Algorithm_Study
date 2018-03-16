#include <stdio.h>

int main() {
	int n, line = 1, ans;
	scanf("%d", &n);
	if (n == 1) 
		printf("1/1");
	else {
		while (1) {
			line++;
			if (line*(line - 1) / 2 + 1 <= n && n <= line*(line + 1) / 2)
				break;
		}
		ans = line - (line - (n - (line*(line - 1) / 2 + 1))) + 1;
		if (line % 2 == 0)
			printf("%d/%d", ans, (line - (n - (line*(line - 1) / 2 + 1))));
		
		else
			printf("%d/%d", (line - (n - (line*(line - 1) / 2 + 1))), ans);
		}
}