#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	char msg[123];
	scanf("%d %d %s", &n, &k, msg);
	int len = strlen(msg);
	vector<int> seq(n);
	for (int i = 0; msg[i] != '\0'; ++i) 
		seq[i] = msg[i] - 'a' + 1;
	sort(seq.begin(), seq.end());
	seq.erase(unique(seq.begin(), seq.end()), seq.end());

	vector<int> ans;
	int sum = seq[0];
	if (k == 1) {
		printf("%d", sum);
		return 0;
	}
	ans.push_back(seq[0]);
	for (int i = 1; i < seq.size(); ++i) {
		if (seq[i] - ans.back() > 1) {
			ans.push_back(seq[i]);
			sum += seq[i];
		}
		if (ans.size() == k) {
			printf("%d", sum);
			return 0;
		}
	}
	printf("-1");
}