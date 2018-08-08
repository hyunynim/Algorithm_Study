#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main() {
	vector<int> seq;
	vector<int> permute;
	while (1) {
		seq.clear();
		permute.clear();
		int n;
		scanf("%d", &n);
		if (n == 0)
			return 0;
		seq.resize(n);
		permute.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &seq[i]);
			if (i < 6)
				permute[i] = 1;
			else
				permute[i] = 0;
		}
		sort(seq.begin(), seq.end());
		do {
			for (int i = 0; i < n; ++i) {
				//printf("%d", permute[i]);
				if (permute[i])
					printf("%d ", seq[i]);
			}
			printf("\n");
		} while (prev_permutation(permute.begin(), permute.end()));
		printf("\n");
	}
}