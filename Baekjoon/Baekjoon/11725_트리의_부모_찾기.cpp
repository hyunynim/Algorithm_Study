#include <iostream>

int main() {
	int n;
	scanf("%d", &n);
	int * num = new int[n + 2];
	int tmp1, tmp2;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		num[tmp2] = tmp1;
	}
	
	for (int i = 2; i <= n; i++)
		printf("%d\n", num[i]);
}


/*commnet*/
//너무 만만하게 봤음 이거 아닐듯