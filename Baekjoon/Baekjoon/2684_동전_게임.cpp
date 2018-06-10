#include<cstdio>

int main() {
	int p;
	scanf("%d", &p);
	for (int i = 0; i < p; ++i) {
		char msg[50];
		int res[8] = { 0 };
		scanf("%s", msg);
		for (int j = 0; j < 38; ++j) {
			if(msg[j] == 'T') {
				if(msg[j + 1] == 'T' && msg[j + 2] == 'T') ++res[0];
				if(msg[j + 1] == 'T' && msg[j + 2] == 'H') ++res[1];
				if(msg[j + 1] == 'H' && msg[j + 2] == 'T') ++res[2];
				if(msg[j + 1] == 'H' && msg[j + 2] == 'H') ++res[3];
			}
			else {
				if(msg[j + 1] == 'T' && msg[j + 2] == 'T') ++res[4];
				if(msg[j + 1] == 'T' && msg[j + 2] == 'H') ++res[5];
				if(msg[j + 1] == 'H' && msg[j + 2] == 'T') ++res[6];
				if(msg[j + 1] == 'H' && msg[j + 2] == 'H') ++res[7];
			}
		}
		for (int j = 0; j < 8; ++j) {
			printf("%d ", res[j]);
		}
		printf("\n");
	}
}