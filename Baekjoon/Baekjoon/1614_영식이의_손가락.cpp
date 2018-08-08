#include<cstdio>
typedef long long ll;
int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	if (k == 0) {
		if (n == 1)
			printf("0");
		else
			printf("%lld", n - 1);
	}
	else {
		ll res;
		if (n == 5)
			res = 4 + k * 8;
		else if (n == 1)
			res = k * 8;
		else if (n == 3)
			res = 2 + (k / 2) * 8 + (k % 2) * 4;
		else if (n == 2)
			res = 1 + (k / 2) * 8 + (k % 2) * 6;
		else
			res = 3 + (k / 2) * 8 + (k % 2) * 2;
		printf("%lld", res);
	}
}

/*comment*/
//계산결과가 int 넘어감
//잘못된 계산들 + 길이줄임