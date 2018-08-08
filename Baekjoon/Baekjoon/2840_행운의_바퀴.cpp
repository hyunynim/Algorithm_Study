#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int n, k, num;
	scanf("%d %d", &n, &k);
	vector<int> seq(n);
	char c;
	int cur = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%d %c", &num, &c);
		cur += num;
		cur %= n;
		if (seq[cur] == 0)
			seq[cur] = c;
		else {
			seq[cur] = '?';
		}
	}
	for (int i = 0; i < n; ++i) {
		if (seq[i] == 0) {
			printf("!");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (seq[cur - i < 0 ? cur - i + 8 : cur - i] == 0)
			printf("?");
		else
			printf("%c", seq[cur - i < 0 ? cur - i + 8 : cur - i]);
	}
}

/*comment*/
//!와 ?의 출력 조건을 잘 이해하지 못하겠음