#include<cstdio>

void swap(char * c1, char * c2) {
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int main() {
	char msg[1234];
	scanf("%s", msg);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		swap(&msg[a], &msg[b]);
	}
	printf("%s", msg);
}