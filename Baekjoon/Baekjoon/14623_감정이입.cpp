#include<cstdio>
#include<string.h>
#include<stack>

using namespace std;
typedef long long ll;

ll pow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

void ch2int(char * msg, ll & num) {
	int len = strlen(msg);
	for (int i = 0; i < len; ++i) {
		num += (msg[i]-'0')*pow(2, len - i - 1);
	}
}

int main() {
	char msg[123];
	ll num[2] = { 0 };
	scanf("%s", msg);
	ch2int(msg, num[0]);

	scanf("%s", msg);
	ch2int(msg, num[1]);
	ll res = num[0] * num[1];
	stack<int> sRes;
	while (res > 0) {
		sRes.push(res % 2);
		res /= 2;
	}
	while (sRes.size()) {
		printf("%d", sRes.top());
		sRes.pop();
	}
}