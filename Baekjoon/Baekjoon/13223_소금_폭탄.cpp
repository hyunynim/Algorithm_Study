#include<cstdio>

int main() {
	int hh, mm, ss;
	int tohh, tomm, toss;
	char c;
	scanf("%d%c%d%c%d", &hh, &c, &mm, &c, &ss);
	scanf("%d%c%d%c%d", &tohh, &c, &tomm, &c, &toss);
	int second = (tohh - hh) * 60 * 60 + (tomm - mm) * 60 + toss - ss;
	if (second <= 0) second += 24 * 60 * 60;
	printf("%02d:%02d:%02d\n", second / 60 / 60, second / 60 % 60, second % 60);
}