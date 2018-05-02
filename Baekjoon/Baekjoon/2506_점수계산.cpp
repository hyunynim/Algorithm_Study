#include <iostream>

int main() {
	int n; 
	scanf("%d", &n);
	int res = 0, tmp = 0;
	int * score = new int[n];
	bool isO = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		if (isO == 0 && score[i] == 1) {
			tmp = 1;
			isO = 1;
		}

		else if (isO == 1 && score[i] == 1) 
			tmp++;

		else if (isO == 1 && score[i] == 0) {
			res += tmp*(tmp + 1) / 2;
			tmp = 0;
			isO = 0;
		}
	}
	if(tmp != 0)
		res += tmp*(tmp + 1) / 2;
	printf("%d", res);
}

/*comment*/
//마지막에 tmp가 남아있는 경우를 포함 안시킴