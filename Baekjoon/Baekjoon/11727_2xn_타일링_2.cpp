#include <iostream>
typedef unsigned long long ull;
using namespace std;

ull num[1001] = { 0, 1, 3};

ull calc(int n) {
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