#include <stdio.h>
#include <vector>

using namespace std;

int pow10(int n) {
	int res = 1, p = 10;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 10;
	else {
		while (n > 0) {
			if (n % 2 != 0)
				res *= p;
			p *= p;
			n /= 2;
		}
		return res;
	}
}

int main() {
	int n, i = 0;
	int dig[10] = { 0 }, tmp, chk = 0;
	vector <int> v;
	scanf("%d", &n);
	while(1) {
		if (v.size() != 0) {
			for(int j = 0; j<v.size()-1; j++)
				if(v.at(j) == tmp) chk = 1;
		}
		if (chk == 1) {
			printf("UNHAPPY");
			return 0;
		}
		tmp = 0;
		i = 0;
		
		while (n > 0) {
			dig[i] = n % 10;
			n /= 10;
			i++;
		}
		for (int i = 0; i < 10; i++) {
			if (dig[i] != 0) {
				n += dig[i] * dig[i];
			}
		}
		if (n == 1) {
			printf("HAPPY");
			return 0;1
		}
		for (int i = 0; i < 10; i++) {
			for (int j = i; j < 10; j++) {
				if (dig[i] > dig[j]) {
					tmp = dig[j];
					dig[j] = dig[i];
					dig[i] = tmp;
				}
			}
		}
		tmp = 0;
		for (int i = 0; i < 10; i++) {
			if (dig[i] != 0) {
				tmp += dig[i] * pow10(9 - i);
				dig[i] = 0;
			}
		}
		v.push_back(tmp);
		
	}
}