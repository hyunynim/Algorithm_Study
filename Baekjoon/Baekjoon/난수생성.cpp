#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	FILE * fp = fopen("random.txt", "w");
	FILE * fres = fopen("res.txt", "w");
	int a, b;
	fprintf(fp, "1000000\n");
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++) {
		a = rand() % 1000;
		b = rand() % 1000;
		fprintf(fp, "%d %d\n", a, b);
		fprintf(fres, "%d\n", a + b);
	}
	fclose(fp);
	fclose(fres);
	return 0;
	
}