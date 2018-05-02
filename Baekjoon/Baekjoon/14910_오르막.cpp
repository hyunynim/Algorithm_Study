#include<cstdio>

int main() {
	int n, tmp = -1000000;
	bool sorted = 1;
	while (scanf("%d", &n) != EOF) {
		if (sorted == 0)
			continue;
		if (tmp > n)
			sorted = 0;
		tmp = n;
	}
	if (sorted)
		printf("Good");
	else
		printf("Bad");
}

/*comment*/
//tmp = n ª©∏‘¿Ω