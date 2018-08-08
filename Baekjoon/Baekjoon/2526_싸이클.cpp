#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool chk[123];
int main() {
	int n, p;
	vector<int> seq;
	scanf("%d %d", &n, &p);
	int first, cur;
	first = cur = (n*n) % p;
	seq.push_back(cur);
	while (1) {
		cur = (cur * n) % p;
		if (seq.front() == cur) {
			printf("%d", seq.size());
			return 0;
		}
		auto it = find(seq.begin(), seq.end(), cur);
		if (it != seq.end()) {
			printf("%d", seq.size() - (it - seq.begin()));
			return 0;
		}
		
		seq.push_back(cur);
	}
}


/*comment*/
//항상 첫 수가 사이클의 첫 수라고 보기 힘듦