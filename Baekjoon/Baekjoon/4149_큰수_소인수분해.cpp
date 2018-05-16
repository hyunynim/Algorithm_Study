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

int main() {
	ll n;
	vector<ll> fact;
	scanf("%lld", &n);
	FindPrimeFact(fact, n);
	for (int i = 0; i < fact.size(); ++i)
		printf("%lld\n", fact[i]);
}


/*comment*/
//�ð��ʰ�
//�־��� ��� 2^31���� ����ɼ��� ���� 
//���� O(sqrt(n))�� �ð��ʰ�