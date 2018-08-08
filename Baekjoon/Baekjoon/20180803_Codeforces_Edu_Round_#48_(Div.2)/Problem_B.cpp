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
int kmp(string s, string p) {
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
	return ans.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	string str1, str2;
	cin >> str1 >> str2;
	int a, b;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b;
		--a, --b;
		cout << kmp(str1.substr(a, b - a + 1), str2) << '\n';
	}
}