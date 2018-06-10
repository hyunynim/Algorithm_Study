#include<iostream>
#include<algorithm>

#define pb(x) push_back(x)
typedef long long ll;

using namespace std;

int main() {
	ll m, n, a, b;
	cin >> n >> m >> a >> b;
	if (n % m == 0)
		printf("0");
	else {
		ll burles = m - n % m;
		ll dem = n % m;
		cout << min(burles*a, dem*b);
	}
}