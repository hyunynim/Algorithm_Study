#include<cstdio>
#include<vector>

using namespace std;

int n;
char msg[1234];
char s[12][12];
vector<int> ans;
bool check() {
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += ans[j];
			if ((sum == 0 && s[i][j] != '0')
				|| (sum > 0 && s[i][j] != '+')
				|| (sum < 0 && s[i][j] != '-'))
				return 0;
		}
	}
	return 1;
}
bool check(int end) {
	int sum = 0;
	for (int i = end; i >= 0; --i) {
		sum += ans[i];
		if ((sum == 0 && s[i][end] != '0')
			|| (sum > 0 && s[i][end] != '+')
			|| (sum < 0 && s[i][end] != '-'))
			return 0;
	}
	return 1;
}
bool go(int st) {
	if (st >= n) 
		return check();
	if (s[st][st] == '0') {
		ans[st] = 0;
		if (check(st) && go(st + 1))
			return 1;
	}
	else if(s[st][st] == '+'){
		for (int i = 1; i <= 10; ++i) {
			ans[st] = i;
			if(check(st) && go(st + 1)) return 1;
		}
	}
	else {
		for (int i = -10; i <= -1; ++i) {
			ans[st] = i;
			if(check(st) && go(st + 1)) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %s", &n, msg);
	ans.resize(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j)
			s[i][j] = msg[cnt++];
	}
	go(0);
	for (int i : ans)
		printf("%d ", i);
}