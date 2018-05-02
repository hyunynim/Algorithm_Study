#include <cstdio>


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		char name[101][30];
		int price[101];
		int p;
		scanf("%d", &p);
		for (int j = 0; j < p; ++j) {
			scanf("%d %s", &price[j], name[j]);
		}
		int max = 0, maxIndex = 0;
		for (int j = 0; j < p; ++j) {
			if (price[j] > max) {
				max = price[j];
				maxIndex = j;
			}
		}
		printf("%s\n", name[maxIndex]);
	}
}