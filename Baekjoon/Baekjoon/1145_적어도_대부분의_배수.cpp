#include <cstdio>


int main() {
	int a[5];
	for (int i = 0; i < 5; ++i)
		scanf("%d", &a[i]);
	int i = 1;
	while (1) {
		int cnt = 0;
		for (int j = 0; j < 5; ++j) {
			if (i % a[j] == 0)
				cnt++;
		}
		if (cnt >= 3)
			break;
		++i;
	}
	printf("%d", i);
}