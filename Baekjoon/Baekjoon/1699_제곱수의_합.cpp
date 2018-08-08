#include<cstdio>
#define MIN(x, y) (x) > (y) ? (y) : (x)
int d[123456];

int main() {
	for (int i = 1; i <= 100000; ++i) 
		d[i] = 987654321;
	for (int i = 1; i*i <= 100000; ++i)
		d[i*i] = 1;
	for (int i = 2; i <= 100000; ++i) {
		for (int j = 1; j*j < i; ++j)
			d[i] = MIN(d[i], d[i - j * j] + 1);
	}
	int n;
	scanf("%d", &n);
	printf("%d", d[n]);
}
/*comment*/
//초기화 잘못함