#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

void FindPrimeFact(vector<ll> & fact, ll n) {
	while (n > 1) {
		bool isPrime = 1;
		for (ll i = 2; i <= (ll)sqrt(n); ++i) {
			if (n % i == 0) {
				fact.push_back(i);
				n /= i;
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			fact.push_back(n);
			return;
		}
	}
}

ll GetPhi(ll n) {
	vector<ll> fact;
	FindPrimeFact(fact, n);
	ll res = 1;
	for (int i = 0; i < fact.size(); ++i) {
		if (i == 0 || fact[i - 1] != fact[i])
			res *= (fact[i] - 1);
		else
			res *= fact[i];
	}
	return res;
}

int main() {
	ll n;
	scanf("%lld", &n);
	printf("%lld", GetPhi(n));
}

/*comment*/
//��� + ��������
//���ó� �ð��ʰ�
//987654321984 �̰� �ſ� �����ɸ�
//���μ����� ������� ����