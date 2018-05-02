#include <iostream>

using namespace std;

unsigned long long int num[1001] = { 0, 1, 3};

unsigned long long int calc(int n) {
	if (num[n] == 0) {
		if (calc(n - 1) % 10007 + 2*calc(n - 2) % 10007 > 10007)
			num[n] = (calc(n - 1) + 2*calc(n - 2) % 10007);
		else
			num[n] = calc(n - 1) % 10007 + 2 * calc(n - 2) % 10007;
	}
	return num[n] % 10007;
}

int main() {
	int n;
	cin >> n;
	cout << calc(n);
	return 0;
}