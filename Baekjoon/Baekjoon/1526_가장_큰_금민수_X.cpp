#include <cstdio>
#include <stack>

using namespace std;

int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int con4(int n) {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res = res * 10 + 4;
	return res;
}

int con7(int n) {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res = res * 10 + 7;
	return res;
}

int main() {
	int n;
	stack <int> num;
	scanf("%d", &n);
	int exp = 6;
	
	while (n / pow(10, exp) == 0)
		exp--;
	
	int res = 0;
	int next = 0;
	if (con4(exp + 1) <= n && n <= con7(exp + 1)) {
		while (n > 0) {
			int tmp = n / pow(10, exp);

			if (tmp > 7) {
				for (int i = 0; i<=exp; ++i)
					res = res * 10 + 7;
				n = 0;
			}
			else if (tmp == 7)
				res = res * 10 + 7;
			else if (tmp > 4) {
				res = res * 10 + 4;
				for (int i = 0; i<exp; ++i)
					res = res * 10 + 7;
				n = 0;
			}
			else if (tmp == 4)
				res = res * 10 + 4;
			n %= pow(10, exp);
			exp--;
		}
	}
	else {
		for (int i = 0; i<exp; ++i)
			res = res * 10 + 7;
		n = 0;
	}
	
	printf("%d", res);
}

/*comment*/
//생각보다 복잡하네 하..