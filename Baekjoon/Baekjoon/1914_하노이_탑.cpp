#include<cstdio>
#include<algorithm>
#include<deque>
#include<stack>
#include<string.h>
#define MAX_STRING_LENGTH 1000
typedef long long ll;

using namespace std;
deque<int> stick[4];

int k = 0;

int NextTarget(int from, int target) {
	int calc = from * 10 + target;
	switch (calc) {
	case 12:
		return 3;
	case 13:
		return 2;
	case 21:
		return 3;
	case 23:
		return 1;
	case 31:
		return 2;
	case 32:
		return 1;
	}
}
ll pow2(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}
void hanoi(int num, int from, int target) {
	if (stick[from].front() != num) {
		hanoi(num - 1, from, NextTarget(from, target));
		printf("%d %d\n", from, target);
		stick[target].push_front(stick[from].front());
		stick[from].pop_front();
		hanoi(num - 1, NextTarget(from, target), target);
	}
	else {
		printf("%d %d\n", from, target);
		stick[target].push_front(stick[from].front());
		stick[from].pop_front();
	}
	++k;
}

void sum(char * a, char * b) {
	stack <char> num1, num2, num3;
	int i, j, tmp;
	int chkNextDegree = 0;

	for (i = 0, j = 0; a[i] != '\0'; i++, j++) {
		num1.push(a[i] - '0');
		num2.push(b[j] - '0');
	}

	while (i && j) {
		tmp = 0;
		if (i != 0)
			tmp += num1.top();
		if (j != 0)
			tmp += num2.top();
		if (chkNextDegree == 1)
			tmp += 1;

		if (num1.top() + num2.top() + chkNextDegree >= 10)
			chkNextDegree = 1;
		else
			chkNextDegree = 0;

		tmp %= 10;
		num3.push(tmp);

		if (i != 0)
			num1.pop();
		if (j != 0)
			num2.pop();
		i--;
		j--;
	}
	while (num1.size()) {
		num3.push((num1.top() + chkNextDegree) % 10);
		chkNextDegree = num1.top() = (num1.top() + chkNextDegree) / 10;
		num1.pop();
	}
	while (num2.size()) {
		num3.push((num2.top() + chkNextDegree) % 10);
		chkNextDegree = num2.top() = (num2.top() + chkNextDegree) / 10;
		num2.pop();
	}
	if (chkNextDegree == 1)
		num3.push(1);
	int tt = 0;
	while (num3.size()) {
		a[tt] =  num3.top() + '0';
		num3.pop();
		++tt;
	}
	a[tt] = '\0';
}

void ll2Char(ll num, char * msg) {
	stack<int> tmp;
	while (num > 0) {
		tmp.push(num % 10 + '0');
		num /= 10;
	}
	int k = 0;
	while (tmp.size()) {
		msg[k] = tmp.top();
		tmp.pop();
		++k;
	}
	msg[k] = '\0';
}

int main() {
	char a[MAX_STRING_LENGTH], b[MAX_STRING_LENGTH];
	ll n;
	scanf("%lld", &n);
	if(n <= 62)
		printf("%lld\n", pow2(2, n) - 1);
	else {
		ll tmp = pow2(2, 62);
		ll2Char(tmp, a);
		for (int i = 0; i < n - 62; ++i) {
			sum(a, a);
		} 
		char ctmp = a[strlen(a) - 1];
		a[strlen(a) - 1] = '\0';
		printf("%s", a);
		printf("%c", ctmp - 1);
	}
	if (n <= 20) {
		for (int i = 1; i <= n; ++i)
			stick[1].push_back(i);
		hanoi(n, 1, 3);
	}
}