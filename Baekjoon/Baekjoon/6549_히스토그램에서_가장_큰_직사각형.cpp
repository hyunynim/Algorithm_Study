#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> h;

long long FindHeight(long long l, long long r) {
	if (l == r)
		return h[l];

	long long mid = (l + r) / 2;

	long long res = max(FindHeight(l, mid), FindHeight(mid + 1, r));

	long long lo = mid, hi = mid + 1;
	long long height = min(h[lo], h[hi]);

	res = max(res, height * 2);

	while (l < lo || hi < r) {
		if (hi < r && (lo == l || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		res = max(res, height * (hi - lo + 1));
	}
	return res;
}

int main() {
	long long n , tmp;
	while (1) {
		scanf("%lld", &n);
		if (n == 0)
			return 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			h.push_back(tmp);
		}
		printf("%lld\n", FindHeight(0, n - 1));
		h.clear();
	}
}

/*comment*/
//overflow 고려 안함