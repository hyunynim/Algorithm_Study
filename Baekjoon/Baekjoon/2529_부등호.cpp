#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> maxSeq;
vector<int> minSeq;
int n;
bool b[12];	// 0< 1>

bool chk(vector<int> & seq) {
	bool ans = 1;
	for (int i = 0; i < n; ++i) {
		ans &= (b[i] ? (seq[i] > seq[i + 1]) : (seq[i] < seq[i + 1]));
	}
	return ans;
}

int main() {
	char msg[12];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		if (msg[0] == '<')
			b[i] = 0;
		else
			b[i] = 1;
	}
	for (int i = 0; i < n + 1; ++i) {
		maxSeq.push_back(9 - i);
		minSeq.push_back(i);
	}
	do {
		if (chk(minSeq))
			break;
	} while (next_permutation(minSeq.begin(), minSeq.end()));
	do {
		if (chk(maxSeq))
			break;
	} while (prev_permutation(maxSeq.begin(), maxSeq.end()));
	for (int i = 0; i < maxSeq.size(); ++i)
		printf("%d", maxSeq[i]);
	printf("\n");
	for (int i = 0; i < minSeq.size(); ++i)
		printf("%d", minSeq[i]);
}