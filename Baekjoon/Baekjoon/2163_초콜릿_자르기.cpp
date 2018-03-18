#include <stdio.h>

int main() {
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	if (n < m) {
		tmp = n;
		n = m;
		m = tmp;
	}
	printf("%d", (m-1) + m*(n-1));
}

/*commnet*/
// 식 정확하게 바꿈