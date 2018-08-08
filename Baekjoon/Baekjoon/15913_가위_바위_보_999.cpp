#include<cstdio>
typedef long long ll;
#define lll __int128
int main() {
	ll * t1 = new ll;
	ll * t2 = new ll;
	printf("%lld", (ll)((ll)t1*(ll)t2)%3);
}