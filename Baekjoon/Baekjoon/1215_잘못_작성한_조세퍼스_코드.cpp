#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

ll naive(ll n, ll k) {
	ll res = 0;
	for (ll i = 1; i <= n; ++i)
		res += k % i;
	return res;
}

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll res = 0;
	ll i = 1;
	if (n > k) 
		res = (n - k)*k;
	else if (n < k) {
		while (k / i > n)
			++i;
		res = (k%n + (k % ((k / i) + 1))) * (n - (k / i)) / 2 ;
	}
	for (; k/i != (k/(i+1)+1)  ; ++i) {
		ll first = k % (k / i);
		ll last = k % (k / (i + 1) + 1);
		res += (first + last)*((k / i) - (k / (i + 1))) / 2;
	}
	for (int j = 2; j <= k / (i); ++j)
		res += k % j;
	printf("%lld", res);
}

/*comment*/
//���������� ���������� ������ ��Ÿ�� �� ����
//�信 �ణ ������ ����
//������ / ���ϱ� ���� �ٲ��ֱ� �Ѥ�; �̰� �� ������ ������ �� ��������
//n < k �� ��� �� �ȵ� �� �ȵɱ�?
//�ֱ� ��û�� �տ��� ������ �ȹٲ����ϱ� �ȵǴ°���
//�ð��ʰ��� ���� ���� ���� �� ������