#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

vector<ll> seq;
int k, n;
priority_queue<ll, vector<ll>, greater<ll>> q;
ll pow(ll a, int n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

void getMul(vector<ll> & pick) {
	ll res = 1;
	for (int i = 0; i < pick.size(); ++i) {
		res *= pick[i];
		if (res > 4200000000LL)
			return;
	}
	q.push(res);
}

void pick(vector<ll> & picked, int toPick, int prev) {
	if (toPick == 0)
		getMul(picked);
	else {
		int next = picked.empty() ? 0 : prev;
		for (int i = next; i < seq.size(); ++i) {
			picked.push_back(seq[i]);
			pick(picked, toPick - 1, i);
			picked.pop_back();
		}
	}
}
int main() {
	scanf("%d %d", &k, &n);
	seq.resize(k);
	for (int i = 0; i < k; ++i) {
		scanf("%lld", &seq[i]);
		q.push(seq[i]);
	}
	if (n <= k) {
		printf("%lld", seq[n - 1]);
		return 0;
	}
	sort(seq.begin(), seq.end());
	vector<ll> vtmp;
	int tmp = 0;
	for (int i = 2; ; ++i) {
		ll ltmp = pow(seq[0], i);
		while (q.size() && q.top() < ltmp) {
			q.pop();
			--n;
			if (n == 1) {
				printf("%lld", q.top());
				return 0;
			}
		}
		pick(vtmp, i, 0);
		tmp = q.size();
	}
}


/*comment*/
//메모리를 더 효율적으로 사용할 방법을 생각해봅시다