#include<cstdio>
#include<string.h>
typedef long long ll;
ll com[33];
int x[33];	// |
int y[33];
int n;
int next, tmp;

void cnt() {
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (com[i] & (1 << j)){
				x[j]++;
				y[i]++;
			}
		}
	}
}

void setCom(bool rc, int ind) {
	if (rc) {
		if (next)
			com[ind] = (1 << n) - 1;
		else
			com[ind] = 0;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (next)
				com[i] |= (1 << ind);

			else
				com[i] &= ~(1 << ind);	
		}
	}
	cnt();
}

bool chk() {
	if (next) {
		for (int i = 0; i < n; ++i) {
			if (com[i] != (1 << n) - 1)
				return 0;
		}
		return 1;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (com[i] != 0)
				return 0;
		}
		return 1;
	}
}

int main() {
	scanf("%d %d", &n, &next);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			if (tmp)
				com[i] |= (1 << j);
		}
	}
	cnt();

	for (int TC = 0; TC < 512; ++TC) {
		for (int i = 0; i < n; ++i) {
			if (next) {
				if (y[i] > n / 2 && y[i] != n)
					setCom(1, i);
				if (x[i] > n / 2 && x[i] != n)
					setCom(0, i);
			}
			else {
				if (y[i] <= n / 2 && y[i] != 0)
					setCom(1, i);
				if (x[i] <= n / 2 && x[i] != 0)
					setCom(0, i);
			}
		}
	}

	printf("%d", chk());
}