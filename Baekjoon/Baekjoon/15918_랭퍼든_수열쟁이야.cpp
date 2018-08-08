#include<cstdio>
int n, x, y;
int con;
int seq[123];
int ans;
void chk() {
	if (seq[x] == seq[y])
		++ans;
}

void go(int prev) {
	if (prev == n)
		chk();
	else {
		bool numChk[33] = { 0 };
		int next = prev + 1;
		if (next == con)
			go(next);
		for (int i = 0; i < 2*n; ++i) {
			if (seq[i] == 0 && !numChk[i]) {
				seq[i] = next;
				numChk[i] = 1;
				if (i - next - 1 >= 0 && seq[i - next - 1] == 0) {
					seq[i - next - 1] = next;
					numChk[i - next - 1] = 1;
					go(next);
					seq[i - next - 1] = 0;
				}
				if (i + next + 1 < 2*n && seq[i + next + 1] == 0) {
					seq[i + next + 1] = next;
					numChk[i + next + 1] = 1;
					go(next);
					seq[i + next + 1] = 0;
				}
				seq[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &x, &y);
	con = y - x - 1;
	--x;
	--y;
	seq[x] = seq[y] = con;
	go(0);
	printf("%d", ans);
}
