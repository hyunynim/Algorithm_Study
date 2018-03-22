#include <stdio.h>

int main() {
	int n;
	int no, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &no);
		if (no == n)
			ans++;
	}
	printf("%d", ans);
}