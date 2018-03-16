#include <iostream>

int main() {
	int n;
	int tmp;
	scanf("%d", &n);
	int * dat = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &dat[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (dat[i] > dat[j]) {
				tmp = dat[i];
				dat[i] = dat[j];
				dat[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", dat[i]);
}