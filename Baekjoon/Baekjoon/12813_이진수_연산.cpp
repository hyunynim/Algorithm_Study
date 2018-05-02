#include <iostream>

int main() {
	char a[100001], b[100001];

	char ans[5][100001];

	scanf("%s %s", a, b);
	for (int i = 0; i < 100000; ++i) {
		if (a[i] == b[i] && a[i] == '1') {
			ans[0][i] = '1';
		}
		else
			ans[0][i] = '0';
		if(a[i] == b[i])
			ans[2][i] = '0';

		else if (a[i] != b[i]) {
			ans[0][i] = '0';
			ans[2][i] = '1';
		}
		if (a[i] == '1' || b[i] == '1')
			ans[1][i] = '1';
		else
			ans[1][i] = '0';
		if (a[i] == '1')
			ans[3][i] = '0';
		else
			ans[3][i] = '1';
		if (b[i] == '1')
			ans[4][i] = '0';
		else
			ans[4][i] = '1';
	}
	for (int i = 0; i < 5; i++) {
		ans[i][100000] = '\0';
		printf("%s\n", ans[i]);
	}
}