#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		char msg[100];
		vector<int> seq;
		scanf("%s", msg);
		for (int i = 0; msg[i] != 0; ++i)
			seq.push_back(msg[i] - '0');
		if (next_permutation(seq.begin(), seq.end())) {
			for (int i = 0; i < seq.size(); ++i)
				printf("%d", seq[i]);
		}
		else
			printf("BIGGEST");
		printf("\n");
		seq.clear();
	}
}