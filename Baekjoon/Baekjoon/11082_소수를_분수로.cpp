#include<cstdio>
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ll pow(ll a, int n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}
int main() {
	char msg[12345];
	scanf("%s", msg);
	int p = -1;
	int b = -1;
	for (int i = 0; msg[i] != '\0'; ++i) {
		if (msg[i] == '.') {
			p = i;
		}
		if (msg[i] == '(')
			b = i;
	}
	if (p == -1) {
		printf("%s/1", msg);
	}
	else {
		ll real = 0, numer = 0, denom = 1, v_gcd;
		for (int i = 0; i < p; ++i)
			real = real * 10 + msg[i] - '0';
		int n = 0;
		if (b == p+1) {
			for (int i = p + 2; msg[i] != ')'; ++i) {
				numer = numer * 10 + msg[i] - '0';
				++n;
			}
			denom = (pow(10, n) - 1)*pow(10, n);
			numer = numer*pow(10, n);
		}
		else if (b != -1) {
			for (int i = p + 1; msg[i] != '('; ++i) {
				numer = numer * 10 + msg[i] - '0';
				++n;
			}
			denom = pow(10, n);
			v_gcd = gcd(denom, numer);
			denom /= v_gcd;
			numer /= v_gcd;

			int n2 = 0;
			ll denom2 = 0, numer2 = 0;
			for (int i = b + 1; msg[i] != ')'; ++i) {
				numer2 = numer2 * 10 + msg[i] - '0';
				++n2;
			}
			denom2 = (pow(10, n2) - 1)*pow(10, n + n2);
			numer2 = numer2 * pow(10, n2);

			ll v_gcd2 = gcd(denom2, numer2);
			denom2 /= v_gcd2;
			numer2 /= v_gcd2;

			numer = numer * denom2 + numer2 * denom;
			denom = denom * denom2;
		}
		else {
			for (int i = p + 1; msg[i] != '\0'; ++i) {
				numer = numer * 10 + msg[i] - '0';
				++n;
			}
			denom = pow(10, n);	
		}
		v_gcd = gcd(denom, numer);
		denom /= v_gcd;
		numer /= v_gcd;
		numer += real * denom;
		v_gcd = gcd(denom, numer);
		denom /= v_gcd;
		numer /= v_gcd;
		printf("%lld/%lld", numer, denom);
	}
}

/*comment*/
//일반 소수와 순환 소수가 섞여있는 경우 처리 안함