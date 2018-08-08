#include<cstdio>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;

ll love(ll a) {
	stack<int> st;
	while (a > 0) {
		st.push(9 - a % 10);
		a /= 10;
	}
	ll res = 0;
	while (st.size()) {
		res = res * 10 + st.top();
		st.pop();
	}
	return res;
}

ll power(int a, int n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		ll num;
		scanf("%lld", &num);
		ll tmp = num;
		int cnt = 0;
		while (tmp > 0) {
			tmp /= 10;
			++cnt;
		}
		ll chk = power(10, cnt - 1);
		if (power(10, cnt) > num && num >= 5 * chk - 1)
			printf("%lld\n", (5 * chk - 1)*(5 * chk));
		else
			printf("%lld\n", num * love(num));
	}
}