#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> pre(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i<m; i++) {
		while (j>0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}

int main() {
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 1; i <= str.length(); ++i) {
		auto pi = pre(str.substr(str.length() - i, str.length()));
		auto res = minmax_element(pi.begin(), pi.end());
		ans = max(ans, *res.second);
	}
	printf("%d", ans);
}