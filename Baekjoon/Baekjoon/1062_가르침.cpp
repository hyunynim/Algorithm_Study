#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int word[123];
int n, k;
vector<int> alpha;
int findWord;
int ans = 0;

int getAns(int f) {
	f = ~f;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if ((word[i] & f) == 0)
			++res;
	}
	return res;
}

void sel(int toPick, vector<int> pick, int prev) {
	if (toPick == 0) {
		int mask = (1 << 0) + (1 << ('c' - 'a')) + (1 << ('n' - 'a')) + (1 << ('t' - 'a')) + (1 << ('i' - 'a'));
		for (int i = 0; i < pick.size(); ++i) 
			mask |= (1 << pick[i]);
		ans = max(ans, getAns(mask));
	}
	else {
		int next = pick.empty() ? 0 : prev + 1;
		for (int i = next; i < alpha.size(); ++i) {
			pick.push_back(alpha[i]);
			sel(toPick - 1, pick, i);
			pick.pop_back();
		}
	}
}

int main() {
	cin >> n >> k;
	if (k < 5)
		printf("0");
	else {
		string str;
		vector<int> permute;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			int len = str.length();
			for (int j = 4; j < len - 4; ++j) {
				word[i] |= (1 << (str[j] - 'a'));
				if (str[j] != 'a' && str[j] != 'c' && str[j] != 'n'
					&& str[j] != 't' && str[j] != 'i')
					alpha.push_back(str[j] - 'a');
			}
		}
		sort(alpha.begin(), alpha.end());
		alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
		if (alpha.size() <= k - 5)
			printf("%d", n);
		else {
			vector<int> vtmp;
			sel(k - 5, vtmp, 0);
			printf("%d", ans);
		}
	}
}