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
//나머지들은 등차수열의 합으로 나타낼 수 있음
//답에 약간 오차가 생김
//나누기 / 곱하기 순서 바꿔주기 ㅡㅡ; 이걸 왜 생각을 안했지 감 떨어진듯
//n < k 인 경우 잘 안됨 왜 안될까?
//왜긴 멍청아 앞에는 계산순서 안바꿨으니까 안되는거지
//시간초과뜸 나름 많이 줄인 것 같은데