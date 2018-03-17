#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 999999
int ans[ARRAY_SIZE] = {1};


int math(int n) {
	int res;
	if (n < ARRAY_SIZE && ans[n] != 0)
		return ans[n];
	else {
		if (n < ARRAY_SIZE) {
			res = ((math(n - sqrt(n)))%1000000 + (math((int)log(n)))%1000000 + (math((int)(sin(n)*sin(n) *(double)n))%1000000))%1000000;
			ans[n] = res;
			return res;
		}
		else
			return ((math(n - (int)sqrt(n))) % 1000000 + (math((int)log(n))) % 1000000 + (math((int)(sin(n)*sin(n) *(double)n)) % 1000000)) % 1000000;
	}
}

int main() {
	int k= 1;
	while (1) {
		scanf("%d", &k);
		if (k == -1)
			return 0;
		printf("%d\n", math(k));
		
	}
}

/*comment*/
//초기값에 이상한 값을 넣어놓음