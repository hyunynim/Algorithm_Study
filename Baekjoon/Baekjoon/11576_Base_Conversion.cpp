#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, k, n;
	ll res = 0;
	scanf("%lld %lld %lld", &a, &b, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%lld", &n);
		res = res * a + n;
	}
	stack<ll> ans;
	while (res > 0)
	{
		ans.push(res%b);
		res /= b;
	}
	while (ans.size()) {
		printf("%lld ", ans.top());
		ans.pop();
	}
}