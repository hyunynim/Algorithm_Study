#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> seq;

int main() {
	int n, k, tmp;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());
	printf("%d", seq[k-1]);
}