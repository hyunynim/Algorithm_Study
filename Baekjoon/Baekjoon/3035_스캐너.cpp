#include<cstdio>

int main() {
	int r, c, zr, zc;
	scanf("%d %d %d %d", &r, &c, &zr, &zc);
	char msg[51][51];

	for (int i = 0; i < r; ++i)
		scanf("%s", msg[i]);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < zr; ++j) {
			for (int l = 0; msg[i][l] != '\0'; ++l) {
				for (int k = 0; k < zc; ++k) {
					printf("%c", msg[i][l]);
				}
			}
			printf("\n");
		}
	}
}

/*comment*/
//행을 잘못읽음