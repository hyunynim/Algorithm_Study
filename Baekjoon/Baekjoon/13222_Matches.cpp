#include<cstdio>

int main() {
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);
	int a;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (a*a <= w*w + h*h)
			printf("YES\n");
		else
			printf("NO\n");
	}
}