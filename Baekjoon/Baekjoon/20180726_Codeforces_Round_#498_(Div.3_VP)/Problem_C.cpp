#include<iostream>
#include<algorithm>
#include<string.h>
#include<deque>
#include<utility>

using namespace std;

typedef long long ll;

int main() {
	ll n, tmp;
	cin >> n;
	deque<ll> seq;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		seq.push_back(tmp);
	}
	if (n == 1) {
		printf("0");
	}
	else if (n == 2) {
		if (seq.front() == seq.back())
			cout << seq.front();
		else
			printf("0");
		return 0;
	}
	else {
		ll ans = 0;
		ll l = 0;
		ll r = 0;
		while (seq.size()) {
			if (l <= r) {
				l += seq.front();
				seq.pop_front();
			}
			else {
				r += seq.back();
				seq.pop_back();
			}
			if (l == r)
				ans = l;
		}
		cout << ans;
	}
	
}