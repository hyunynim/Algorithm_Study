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
	int i = 0;
	for (i = 1; i*i <= n; ++i)
		res += (k%i);

	int iTmp = n / i;
	res += k % iTmp;
	while (1) {
		int tmp = n / i;
		if (tmp == 1) {
			break;
		}
		int tmp2 = n % (tmp - 1) == 0 ? n / (tmp - 1) - 1 : n / (tmp - 1);
		res += (tmp2 - i + 1)*(k%i - k % tmp2) / 2;
		res += (tmp2 - i)*tmp;
		i = tmp2;
	}
	printf("%lld", res);
}

/*comment*/
//���������� ���������� ������ ��Ÿ�� �� ����
//�信 �ణ ������ ����
//������ / ���ϱ� ���� �ٲ��ֱ� �Ѥ�; �̰� �� ������ ������ �� ��������
//n < k �� ��� �� �ȵ� �� �ȵɱ�?
//�ֱ� ��û�� �տ��� ������ �ȹٲ����ϱ� �ȵǴ°���
//�ð��ʰ��� ���� ���� ���� �� ������