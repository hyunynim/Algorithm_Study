#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> seq(3);
	while (1) {
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &seq[i]);
		}
		if (seq[0] == 0 && seq[1] == 0 && seq[2] == 0)
			return 0;
		sort(seq.begin(), seq.end());
		if (seq.back()*seq.back() == seq[0] * seq[0] + seq[1] * seq[1])
			printf("right\n");
		else
			printf("wrong\n");
	}
}