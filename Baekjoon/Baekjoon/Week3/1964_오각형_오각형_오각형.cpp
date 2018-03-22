#include <iostream>

using namespace std;

int main() {
	int n, i, res = 5;
	scanf("%d", &n);
	if (n != 1) {
		for (i = 1; i<n; i++)
			res = (res + 4 + 3 * i) % 45678;
	}
	printf("%d", res);
	return 0;
}