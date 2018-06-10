#include<cstdio>
#include<vector>
#include<functional>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	sort(seq.begin(), seq.end(), greater<int>());

	for (int i = 0; i < n; ++i)
		seq[i] += i + 2;

	sort(seq.begin(), seq.end());

	printf("%d", seq.back());
}