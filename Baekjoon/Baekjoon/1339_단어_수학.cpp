#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
char msg[10][123];
bool chk[30];
int k[1234];
vector<int> seq;
vector<char> alpha;
int calc(char * m1) {
	int a = 0;
	for (int i = 0; m1[i]; ++i) 
		a = a * 10 + seq[k[m1[i]]];
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", msg[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; msg[i][j]; ++j)
			chk[msg[i][j] - 'A'] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < 30; ++i) {
		if (chk[i]) {
			alpha.push_back(i + 'A');
			k[i + 'A'] = cnt;
			++cnt;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		seq.push_back(9 - i);
	}
	int ans = 0;
	do {
		int tmp = 0;
		for (int i = 0; i < n; ++i)
			tmp += calc(msg[i]);
		ans = max(tmp, ans);
	} while (prev_permutation(seq.begin(), seq.end()));
	printf("%d", ans);
}

/*comment*/
//A-J까지만 생각함