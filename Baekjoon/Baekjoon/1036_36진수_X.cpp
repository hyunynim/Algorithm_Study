#include <iostream>
#include <string.h>

int main() {
	int n, maxLen = -10;
	scanf("%d", &n);
	char ** num = new char *[n];
	int * numLen = new int[n];
	for (int i = 0; i < n; ++i) {
		num[i] = new char[51];
		scanf("%s", num[i]);
		numLen[i] = strlen(num[i]);
		if (numLen[i] > maxLen)
			maxLen = numLen[i];
	}
	char tmp[51];
	int itmp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (strcmp(num[i], num[j])) {
				strcpy(tmp, num[i]);
				strcpy(num[i], num[j]);
				strcpy(num[j], tmp);
				itmp = numLen[i];
				numLen[i] = numLen[j];
				numLen[j] = itmp;
			}
		}
	}

	int k;
	scanf("%d", &k);
	itmp = k;
	char * change = new char[k];
	int chIndex = 0;
	while (k) {
		for (int i = 0; i < n; ++i) {
			if (numLen[i] == maxLen) {
				if (num[i][0] != 'Z') {
					change[chIndex] = num[i][0];
					k--;
				}
			}
			if (k == 0)
				break;
		}
	}

	for (int i = 0; i < itmp; ++i)
		printf("%c", change[i]);
}


/*comment*/
//GG... 아직 내공이 모자람