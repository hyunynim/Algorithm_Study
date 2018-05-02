#include <iostream>
#include <algorithm>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[9];
		scanf("%s", msg);
		int cnt = 0;
		while (std::prev_permutation(msg, &msg[8]))
			++cnt;
		printf("%d\n", cnt+1);
	}
}