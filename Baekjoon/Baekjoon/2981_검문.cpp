#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main() {
	int n, tmp;
	vector<int> seq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());

	vector<int> sub;
	for (int i = 1; i < seq.size(); ++i)
		sub.push_back(seq[i] - seq[i - 1]);
	
	tmp = sub[0];
	
	for (int i = 1; i < sub.size(); ++i) {
		tmp = GCD(tmp, sub[i]);
	}
	
	seq.clear();

	for (int i = 2; i <= sqrt(tmp); ++i) {
		if (tmp % i == 0)
			seq.push_back(i);
	}
	for (int i = 0; i < seq.size(); ++i)
		printf("%d ", seq[i]);
	for (int i = seq.size() - 1; i >= 0; --i) {
		if (i == seq.size() - 1 && tmp / seq[i] == seq.back())
			continue;
		printf("%d ", tmp / seq[i]);
	}
	printf("%d", tmp);
}

/*comment*/
//GCD에 sub[1]으로 오타나있었음
//시간초과
//약수를 sqrt(tmp)까지만 구해서 그 구한수로 나눠서 나머지 약수 구함