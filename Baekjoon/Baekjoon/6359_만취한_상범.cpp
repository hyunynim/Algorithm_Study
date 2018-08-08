#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

void FindDiv(vector<ll> & div, ll n) {
	for (ll i = 2; i <= (ll)sqrt(n); ++i) {
		if (n % i == 0)
			div.push_back(i);
	}
	for (ll i = div.size() - 1; i >= 0; --i) {
		if (i == div.size() - 1 && n / div[i] == div.back())
			continue;
		div.push_back(n / div[i]);
	}
	div.push_back(n);
}

int d[123] = { 0,0,0,0,0,2 };
int main() {
	bool room[101];
	for (int i = 0; i <= 100; ++i)
		room[i] = 1;
	int t;
	scanf("%d", &t);
	vector<ll> vtmp;
	for (int i = 6; i < 101; ++i) {
		vtmp.clear();
		FindDiv(vtmp, i);
		if (vtmp.size() % 2)
			d[i] = d[i - 1];
		else
			d[i] = d[i - 1] + 1;
	}
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}

}