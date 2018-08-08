#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> seq;
	for (int i = 0; i < n; i++)
		seq.push_back(i + 1);
	if (n == 1) {
		printf("<1>");
		return 0;
	}
	printf("<%d, ", seq[k-1]);
	int cnt = k - 1;
	seq.erase(seq.begin() + cnt);
	while (seq.size() != 1) {
		cnt += k;
		--cnt;
		cnt %= seq.size();
		printf("%d, ", seq[cnt]);
		seq.erase(seq.begin() + cnt);
	}


	printf("%d>", seq[0]);
}
/*comment*/
//n == 1 인 case 예외처리