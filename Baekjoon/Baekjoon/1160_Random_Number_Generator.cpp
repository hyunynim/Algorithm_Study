#include<cstdio>

typedef long long ll;
using namespace std;
ll m, a, c, X, n, g;
ll matrix[2][2] = { {0,0}, {1,1} };
ll pow(ll n, ll m) {
	ll res[2][2] = { { 1,0 },{ 0,1 } }, tmp[2][2];
	while (n > 0) {
		if (n % 2 != 0) {
			tmp[0][0] = ((matrix[0][0] * res[0][0]) % m + (matrix[1][0] * res[0][1]) % m) % m;
			tmp[1][0] = ((matrix[0][0] * res[1][0]) % m + (matrix[1][0] * res[1][1]) % m) % m;
			tmp[0][1] = 0;
			tmp[1][1] = 1;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++)
					res[i][j] = tmp[i][j];
			}
		}
		tmp[0][0] = ((matrix[0][0] * matrix[0][0]) % m + (matrix[0][1] * matrix[1][0]) % m) % m;
		tmp[1][0] = ((matrix[1][0] * matrix[0][0]) % m + (matrix[1][1] * matrix[1][0]) % m) % m;
		tmp[0][1] = 0;
		tmp[1][1] = 1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++)
				matrix[i][j] = tmp[i][j];
		}
		n /= 2;
	}
	printf("%lld\n%lld\n", res[0][0], res[1][0]);
	return ((((X%m)*(res[0][0]%m)) % m) + (((c%m)*(res[1][0]%m)) % m)) % m;
}
int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &X, &n, &g);

	matrix[0][0] = a;
	ll res = pow(n, m);

	printf("%lld", res%g);
}

/*comment*/
//�ð��ʰ�
//������ ������ �ֱ⼺ �̿�
//�� pow�̿�
// (a_n, C) (K 0) ���ϸ� (a_(n+1), C) ����
//          (1 1) 
//res�� ������ķ� ����
//m�� ��ģ���� Ŭ ��쵵 �����ؾ���. �� m�� 1E+17 �̵� ��쿣 ���������� ���ص� overflow �׷��� ��� Ʋ���°ſ��� ��ķ� ���ص� 
//Java�� BigInteger �̿��ؼ� ������ �ôµ� Ʋ��. ��� Ʋ������?