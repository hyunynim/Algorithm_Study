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
//시간초과
//나머지 수열의 주기성 이용
//걍 pow이용
// (a_n, C) (K 0) 곱하면 (a_(n+1), C) 나옴
//          (1 1) 
//res를 단위행렬로 변경
//m이 미친듯이 클 경우도 생각해야함. 즉 m이 1E+17 이딴 경우엔 나머지끼리 곱해도 overflow 그래서 계속 틀리는거였음 행렬로 구해도 
//Java의 BigInteger 이용해서 구현해 봤는데 틀림. 어디가 틀린거지?