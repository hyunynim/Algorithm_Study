#include <iostream>

using namespace std;

int main() {
	int m, n, i, j = 0, res = 0;
	cin >> m >> n;
	for (i = 1; i < 101; i++) {
		if (m <= i * i && i*i <= n) {
			if (j == 0)
				j = i;
			res += i * i;
		}
	}
	if (j != 0) {
		cout << res;
		cout << endl << j * j;
	}
	else
		cout << -1;
	return 0;
}