#include<cstdio>
typedef long long ll;
using namespace std;

ll pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n /= 2;
	}
	return res;
}
int main() {
	ll m, a, c, X, n, g;
	scanf("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &X, &n, &g);
	X = (X*pow(a, n, m))%m;
	c = (n*c) % m;
	X = (X + c) % m;
	//���⼭����

	printf("%lld", X%g);
}

/*comment*/
//�ð��ʰ�
//������ ������ �ֱ⼺ �̿�
//�� pow�̿�