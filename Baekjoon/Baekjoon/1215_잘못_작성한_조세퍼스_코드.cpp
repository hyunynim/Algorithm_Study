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
//나머지들은 등차수열의 합으로 나타낼 수 있음
//답에 약간 오차가 생김
//나누기 / 곱하기 순서 바꿔주기 ㅡㅡ; 이걸 왜 생각을 안했지 감 떨어진듯
//n < k 인 경우 잘 안됨 왜 안될까?
//왜긴 멍청아 앞에는 계산순서 안바꿨으니까 안되는거지
//시간초과뜸 나름 많이 줄인 것 같은데