// + 피자(Large)
#include<cstdio>
typedef long long ll;
ll res = 0;

void getHappy(ll num, ll cnt) {
	if (num <= 1)
		return;
	else {
		res += (num / 2) * (num - num / 2) * cnt;
		if(num/2 == (num-num/2))
			getHappy(num / 2, cnt*2);
		else {
			getHappy(num / 2, cnt);
			getHappy(num - num / 2, cnt);
		}
	}
}

int main() {
	ll n;
	scanf("%lld", &n);
	getHappy(n, 1LL);
	printf("%lld", res);
}

/*comment*/
//getHappy의 parameter로 1이 아닌 cnt를 넘겨줘야 함