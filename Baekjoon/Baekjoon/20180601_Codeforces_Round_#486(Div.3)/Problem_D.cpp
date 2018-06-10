#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
typedef long long ll;
int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	int n, pre[32] = { 0 };
	for (int i = 0; i < 31; ++i) {
		pre[i] = pow(2, i);
	}
	scanf("%d", &n);
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	int maxCnt = 0;
	for (int i = 0; i < seq.size(); ++i) {
		for (int j = 0; j < 31; ++j) {
			if (binary_search(seq.begin(), seq.end(), seq[i] + pre[j]) && binary_search(seq.begin(), seq.end(), seq[i] + 2 * pre[j])) {
				cout << "3\n" << seq[i] << " " << seq[i] + pre[j] << " " << seq[i] + 2 * pre[j];
				return 0;
			}
		}
	}
	for (int i = 0; i < seq.size(); ++i) {
		for (int j = 0; j < 31; ++j) {
			if (binary_search(seq.begin(), seq.end(), seq[i] + pre[j])) {
				cout << "2\n" << seq[i] << " " << seq[i] + pre[j];
				return 0;
			}
		}
	}
	for (int i = 0; i < seq.size(); ++i) {
		for (int j = 0; j < 31; ++j) {
			if (binary_search(seq.begin(), seq.end(), pre[j])) {
				cout << "1\n" << pre[j];
				return 0;
			}
		}
	}
	printf("0");
}

/*comment*/
//하나의 수만 기준으로 했음
//출력을 cout으로 바꿈 -> test4
//1차이도 찾도록 바꿈 -> test4