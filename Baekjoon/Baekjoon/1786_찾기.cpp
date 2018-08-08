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
vector<int> kmp(string s, string p) {
	auto pi = pre(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int i = 0;
	int j = 0;
	for (int i = 0; i<n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	char c;
	string str[2];
	int cnt = 0, f = 0;
	do {
		int ind = scanf("%c", &c);
		if (c == '\n' || ind == EOF) {
			++f;
			if (f == 2)
				break;
			continue;
		}
		str[f] += c;
	} while (1);
	
	auto ans = kmp(str[0], str[1]);
	printf("%d\n", ans.size());
	for (int i : ans)
		printf("%d ", i + 1);
}