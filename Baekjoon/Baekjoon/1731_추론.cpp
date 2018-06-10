#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> seq;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	if (seq[1] - seq[0] == seq[2] - seq[1]) {
		printf("%d", seq.back() + seq[1] - seq[0]);
	}
	else
		printf("%d", seq.back()*(seq[1] / seq[0]));

}

/*comment*/
//if¹®À» Àß¸ø¾¸