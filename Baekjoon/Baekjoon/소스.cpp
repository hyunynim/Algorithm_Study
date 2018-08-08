#include <stdio.h>
#include <vector>

using namespace std;

long long pow10(int n) {
	long long res = 1, tmp = 10;
	while (n > 0) {
		if (n % 2 != 0)
			res *= tmp;
		tmp *= tmp;
		n /= 2;
	}
	return res;
}

int main() {
		vector <long long> fib1, fib2, fib3, tmp;
		fib1.clear();
		fib2.clear();
		fib3.clear();
		tmp.clear();
		long long m = 1000000000000000LL, tmpl = 0;

		fib1.push_back(0);
		fib2.push_back(1);
		int n, ii = 15;
			scanf("%d", &n);
		if (n == 0) {
			printf("0, ");
		}
		for (int i = 2; i <= n; i++) {
			while (fib1.size() != 0 && fib2.size() != 0) {
				fib3.push_back(((fib1.front() + fib2.front() + tmpl) % m));
				tmpl = (fib1.front() + fib2.front() + tmpl) / m;

				fib1.erase(fib1.begin());
				tmp.push_back(fib2.front());
				fib2.erase(fib2.begin());
			}

			if (fib1.size() == 0 && fib2.size() == 0 && tmpl != 0)
				fib3.push_back(tmpl);


			if (fib2.size() != 0) {
				while (fib2.size() != 0) {
					fib3.push_back(fib2.front() + tmpl);
					tmp.push_back(fib2.front());
					fib2.erase(fib2.begin());
					tmpl = 0;
				}
			}


			while (tmp.size() != 0) {
				fib1.push_back(tmp.front());
				tmp.erase(tmp.begin());
			}
			while (fib3.size() != 0) {
				fib2.push_back(fib3.front());
				fib3.erase(fib3.begin());
			}
			tmpl = 0;
		}
		while (fib2.size() != 0) {
			printf("%lld", fib2.back());
			fib2.erase(fib2.end() - 1);
			if (fib2.size() != 0) {
				tmpl = fib2.back();
				ii = 14;
				while (tmpl / pow10(ii) == 0) {
					printf("0");
					ii--;
				}
			}
		}
		printf("\", ");
	
}