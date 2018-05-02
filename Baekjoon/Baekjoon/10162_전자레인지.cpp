#include  <cstdio>

int main() {
	int a = 0, b = 0, c = 0, t;
	scanf("%d", &t);
	if (t % 10) {
		printf("-1");
		return 0;
	}
	else {
		a = t / 300;
		t %= 300;
		b = t / 60;
		t %= 60;
		c = t / 10;
		printf("%d %d %d", a, b, c);
	}
}